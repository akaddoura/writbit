#include "notes.h"
#include "ui_notes.h"
#include "mydb.h"
#include <notesheet.h>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QListWidget>
#include <QLabel>

using namespace cw;

Notes::Notes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notes)
{
    ui->setupUi(this);
    //load_tags();
    buildUI();
    lastNoteID = 0;
    getLastNoteID();
    getTotalNotesCount();
    loadNotes();
    loadTags();
    ui->dialogLayout->setColumnStretch(0, 13);
    ui->dialogLayout->setColumnStretch(1, 50);
    //CurrentIDCount = getLastNoteID();

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(50,50,50));
    palette.setColor(QPalette::Base, QColor(50,50,50));
    palette.setColor(QPalette::Text, QColor(255, 255, 255));
    palette.setColor(QPalette::Button, QColor(100,100,100));

    this->setPalette(palette);

    ui->addNoteButton->setIcon(QIcon(":/icons/plusWhite.png"));
    ui->removeNoteButton->setIcon(QIcon(":/icons/deleteWhite.png"));
    ui->refreshButton->setIcon(QIcon(":/icons/refreshWhite.png"));
    ui->sendToSidePanel->setIcon(QIcon(":/icons/rightWhite.png"));

    QString buttonsStyle(
                "QPushButton {"
                "background: transparent; "
                "text-align: center;"
                "} "
                "QPushButton::pressed {"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                "}");

    ui->addNoteButton->setStyleSheet(buttonsStyle);
    ui->refreshButton->setStyleSheet(buttonsStyle);
    ui->removeNoteButton->setStyleSheet(buttonsStyle);
    ui->sendToSidePanel->setStyleSheet(buttonsStyle);
}

Notes::~Notes()
{
    delete ui;
}

void Notes::buildUI()
{
    list1 = new QWidgetListWidget(nullptr, true, QBoxLayout::Direction::TopToBottom);
    list1->setAcceptDrops(true);
    scroll_list1 = new QWidgetScrollListWidget(list1);
    ui->notesLayout->addWidget(scroll_list1);

//    list2 = new QWidgetListWidget(nullptr, true, QBoxLayout::Direction::LeftToRight);
//    list2->setAcceptDrops(true);
//    scroll_list2 = new QWidgetScrollListWidget(list2);
//    ui->notesLayout->addWidget(scroll_list2);
}

void Notes::loadNotes()
{
    QSqlQuery qry;
    qry.exec("SELECT note_id, note_title, note_content FROM notes;");
    while (qry.next())
    {
        int noteID = qry.value(0).toInt();
        auto noteTitle = qry.value(1).toString();
        auto noteContent = qry.value(2).toString();
        QStringList noteTags;
        QSqlQuery qry2;
        qry2.prepare("SELECT note_id, tag_title FROM tags "
                     "WHERE tags.note_id = ? ;");
        qry2.addBindValue(noteID);
        qry2.exec();
        while(qry2.next())
        {
            //qDebug() << "prepared qry2: " << qry2.executedQuery();
            noteTags << qry2.value(1).toString();
            //qDebug() << "inside loop value print: " << qry2.value(1).toString();
        }
        NoteSheet *newNote = new NoteSheet(noteID, noteTitle, noteContent, noteTags);
        connect(newNote, SIGNAL(noteChanged(bool)), this, SLOT(noteSheetChanged(bool)));
        list1->addItem(newNote);
    }
}

void Notes::on_addNoteButton_clicked()
{
    // create the next ID past the maximum ID in sql, cross check with tags db?
    int32_t nextID = getLastNoteID() + 1;
    //qDebug() << "nextID = " << nextID;
    lastNoteID = nextID;
    //qDebug() << "lastNoteID after push = " << lastNoteID;
    QStringList noteTags;
    list1->addItem(new NoteSheet(nextID, "", "", noteTags));
    QSqlQuery qry;
    qry.prepare("INSERT INTO notes (note_id, note_title, note_content) "
                "VALUES (?, ?, ?);");
    qry.addBindValue(nextID);
    qry.addBindValue("");
    qry.addBindValue("");
    qry.exec();
}

int32_t Notes::getLastNoteID()
{
    QSqlQuery qry;
    qry.prepare("SELECT MAX(note_id) FROM notes;");
    if (!qry.exec())
        qDebug() << "Could not get last noteID";
    while (qry.next())
    {
        int32_t maxID = qry.value(0).toInt();
        if (lastNoteID >= maxID)
            break;
        else
            lastNoteID = maxID;
    }
    //qDebug() << "lastNoteID = " << lastNoteID;
    return lastNoteID;
}

void Notes::getTotalNotesCount()
{
    QSqlQuery qry;
    QSqlQueryModel *m = new QSqlQueryModel;
    qry.prepare("SELECT * FROM notes;");
    if (!qry.exec())
        qDebug() << "Could not get total # of notes";
    m->setQuery(qry);
    notesCount = m->record(1).count();
}

void Notes::loadTags()
{
    ui->tagsList->clear();
    QSqlQuery qry;
    qry.prepare("SELECT tag_title FROM tags "
                "GROUP BY tags.tag_title;");
    if (!qry.exec())
        qDebug() << "Could not load tags into listView";
    QStringList tags;
    while (qry.next())
    {
        tags << qry.value(0).toString();
    }
    tags.removeDuplicates();
    ui->tagsList->insertItems(0, tags);
    ui->tagsList->update();
}

void Notes::on_tagsList_itemClicked(QListWidgetItem *item)
{
    list1->clear();
    QSqlQuery qry;
    qry.prepare("SELECT notes.note_id, note_title, note_content "
                "FROM notes JOIN tags ON notes.note_id = tags.note_id "
                "WHERE tags.tag_title = :tag ;");
    qry.bindValue(":tag", item->text());
    if (!qry.exec())
        qDebug() << "ERROR: could not exec tagsList qry to generate notes from tag" << qry.lastError();
    //qDebug() << "prepared qry: " << qry.executedQuery();
    while (qry.next())
    {
        int noteID = qry.value(0).toInt();
        //qDebug() << "note_id: " << noteID;
        auto noteTitle = qry.value(1).toString();
        auto noteContent = qry.value(2).toString();
        QStringList noteTags;
        QSqlQuery qry2;
        qry2.prepare("SELECT note_id, tag_title FROM tags "
                     "WHERE tags.note_id = ? ;");
        qry2.addBindValue(noteID);
        qry2.exec();
        while(qry2.next())
        {
            //qDebug() << "prepared qry2: " << qry2.executedQuery();
            noteTags << qry2.value(1).toString();
            //qDebug() << "inside loop value print: " << qry.value(1).toString();
        }
        NoteSheet *newNote = new NoteSheet(noteID, noteTitle, noteContent, noteTags);
        connect(newNote, SIGNAL(noteChanged(bool)), this, SLOT(noteSheetChanged(bool)));
        list1->addItem(newNote);
    }
}

void Notes::on_removeNoteButton_clicked()
{
    // display critical confirmation message, add option in settings to
    // ask everytime or not.

    QSqlQuery qry;
    auto itemList = list1->getSelectedItems();
    for (auto i : itemList)
    {
        list1->removeItem(i);
        qry.prepare("DELETE FROM notes WHERE note_id = ? ;");
        qry.addBindValue(i->note_id);
        qry.exec();
        qry.prepare("DELETE FROM tags WHERE note_id = ? ;");
        qry.addBindValue(i->note_id);
        qry.exec();
    }
}

void Notes::on_notesSearchBar_textChanged(const QString &arg1)
{
    qDebug() << "search signal emitted: " << arg1;
    if(arg1 == "")
    {
        ui->tagsList->clear();
        loadTags();
    }
    else
    {
        auto resultTags = ui->tagsList->findItems(arg1, Qt::MatchContains);
        //qDebug() << "result count: " << resultTags.count() << " Empty? " << resultTags.isEmpty();
        QStringList t;
        for (auto i : resultTags)
        {
            t << i->text();
        }
        ui->tagsList->clear();
        ui->tagsList->insertItems(0, t);
        ui->tagsList->update();
    }
}

void Notes::on_refreshButton_clicked()
{
    list1->clear();
    loadNotes();
    ui->tagsList->clear();
    loadTags();
}

void Notes::on_sendToSidePanel_clicked()
{
    auto itemList = list1->getSelectedItems();
    for (auto i : itemList)
    {
        auto n = i->clone();
        emit sendNotes(n);
    }
}

void Notes::on_updateDatabase_clicked()
{
    /* Since the delete note button removes the note from the databases,
     * this button will only update the information for the remaining notes
     * displayed which should match the number of notes and IDs in the
     * database.
     */
    auto currentNotes = list1->getItems();
    foreach (auto i, currentNotes)
    {
        i->saveNote();
    }
    loadTags();
}

void Notes::on_loadDatabase_clicked()
{
    QString filter = "SQLite File (*.sqlite)";
    QString dbName = QFileDialog::getOpenFileName(this, "Open database", "home",
                                                  filter,&filter);
    QFile file(dbName);
    currentDBName = dbName;
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file:" + file.errorString());
        return;
    }
    emit loadNewDB(dbName);
    list1->clear();
    loadNotes();
    loadTags();
}

void Notes::on_newDatabase_clicked()
{
    QString filter = "SQLite File (*.sqlite)";
    QString newDbName = QFileDialog::getSaveFileName(this, "Choose where to save a new database",
                                                     "home", filter, &filter);
    currentDBName = newDbName;
    emit loadNewDB(newDbName);
    list1->clear();
}

void Notes::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Apply")
    {
        qDebug() << "Apply clicked";
        saveNoteChanges();
    }
}

void Notes::saveNoteChanges()
{
    ui->updateDatabase->click();
    qDebug() << "update initiated";
}

void Notes::noteSheetChanged(bool isChanged)
{
    if (isChanged)
        maybeSave = true;
}

void Notes::checkToSave()
{
//    qDebug() << "on_notes_accepted";
//    qDebug() << "maybeSave" << maybeSave;
    if (maybeSave)
    {
        QMessageBox msgBox;
        msgBox.setText("Notes in the database have been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret)
        {
        case QMessageBox::Save:
            saveNoteChanges();
            break;
        case QMessageBox::Discard:
            this->rejected();
            break;
        case QMessageBox::Cancel:
            return;
        default:
            // should never be reached
             break;
        }
    }
}

void Notes::on_buttonBox_accepted()
{
    checkToSave();
    this->accept();
}

QStringList Notes::getCurrentTags()
{
    QStringList currentTagsList;
    auto currentNotes = list1->getItems();
    foreach (auto i, currentNotes)
    {
        currentTagsList << i->getTags();
    }
    currentTagsList.removeDuplicates();
    return currentTagsList;
}
