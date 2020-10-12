/***********************************************************************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * See http://www.gnu.org/licenses/ for a look at the GNU general public
 * license.
 ***********************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace cw;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),    //parent constructor
    ui(new Ui::MainWindow)  //create ui class, assign it to Ui member

{
    ui->setupUi(this);  //sets up user interface, setupUI id s member of Ui

    setCurrentFile(QString());

    //Fullscreen
    this->setCentralWidget(ui->main_frame);     //sets the textEdit window as the main window (fullscreen)
    this->setWindowState(Qt::WindowFullScreen);
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
//    ui->textEdit->setText("The thousand injuries of Fortunato I had borne as I best could, "
//                          "but when he ventured upon insult I vowed revenge. "
//                          "You, who so well know the nature of my soul, will not suppose, "
//                          "however, that gave utterance to a threat.");

    ui->textEdit->setAcceptRichText(false);

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Palette

    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);

    defaultFont.fromString("Courier New,12,-1,5,50,0,0,0,0,0");
    qDebug() << defaultFont.toString();

    QString  MainWindowStyle(
               "QMainWindow::seperator {"
               "background: rgb(0,0,0);"
               "width: 10px; "
               "height: 10px; "
               "}"
               "QMainWindow::separator:hover {"
               "background: rgb(90,90,90)"
               "}");

//    this->setStyleSheet(MainWindowStyle);
//    qDebug() << "useDefaultPalette: " << useDefaultPalette;
//    qDebug() << "Palette p: " << p.color(QPalette::Base);
//    qDebug() << "Palette p: " << p.color(QPalette::Text);
//    qDebug() << "defaultBaseColor: " << defaultBaseColor.rgb();

    if (!currentFile.isEmpty())
        openPrevious(currentFile);
    else
        loadSettings();

    if (useDefaultPalette)
    {
        QPalette p;
        p.setColor(QPalette::Window, defaultWindowColor);
        p.setColor(QPalette::Base, defaultBaseColor);
        p.setColor(QPalette::Text, defaultTextColor);
        p.setColor(QPalette::Button, defaultButtonColor);
        this->setPalette(p);
        currentBackgroundColor  = defaultBaseColor;
        currentTextColor        = defaultTextColor;
        currentWindowColor      = defaultWindowColor;
    }
    else
    {
        QPalette p;
        p.setColor(QPalette::Window, currentWindowColor);
        p.setColor(QPalette::Base, currentBackgroundColor);
        p.setColor(QPalette::Text, currentTextColor);
        p.setColor(QPalette::Button, defaultButtonColor);
        this->setPalette(p);
    }

    QString buttonsStyle(
                "QPushButton {"
                "background: transparent; "
                "text-align: center;"
                "} "
                "QPushButton::pressed {"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                "}");

    ui->addNote->setStyleSheet(buttonsStyle);
    ui->deleteNote->setStyleSheet(buttonsStyle);
    ui->saveNotes->setStyleSheet(buttonsStyle);
    ui->refreshNotes->setStyleSheet(buttonsStyle);

//    QString lineEditStyle(
//                "QLineEdit {"
//                "background: rgb(90,90,90);"
//                "color: white;"
//                "}"
//                );
//    ui->search_bar->setStyleSheet(lineEditStyle);

    QString textEditStyle(
                "QTextEdit {"
                "border: none;"
                "outline: none;"
                "}"
                "QGraphicsView:focus {"
                "border: none;"
                "outline: none;"
                "}"
                );
    //ui->textEdit->setStyleSheet(textEditStyle);
    ui->textEdit->setFrameStyle(QFrame::NoFrame);

    QString  slideButtonStyle(
                "QPushButton {"
                "background: transparent; "
                "text-align: center;"
                "} "
                "QPushButton::pressed {"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                "}");
    //ui->slide_button->setStyleSheet(slideButtonStyle);

    QString  dockStyle(
               "QDockWidget {"
               "background: rgb(31,31,31);"
               "}"
            );
    ui->side_panel->setStyleSheet(dockStyle);

    QString centralStyle(
                "QGraphicsView:focus {"
                 "border: none;"
                 "outline: none;"
                 "}"
             );
    ui->centralwidget->setStyleSheet(centralStyle);

    QString statusBarStyle(
                "QStatusBar {"
                "background: rgb(50,50,50);"
                "}"
                "QStatusBar::item {"
                "border: none;"
                "border-radius: none;"
                "}");
    ui->statusbar->setStyleSheet(statusBarStyle);

    QString wc_display_style(
                "QLabel {"
                "border: none;"
                "color: rgb(90,90,90);"
                "}");

    QString find_bar_style(
                "QLineEdit {"
                "border: none;"
                "background-color: rgb(90,90,90);"
                "color: rgb(255,255,255);"
                "width: 250px;"
                "}");

    ui->saveNotes->setIcon(QIcon(":/icons/saveWhite.png"));
    ui->addNote->setIcon(QIcon(":/icons/addWhite.png"));
    ui->deleteNote->setIcon(QIcon(":/icons/deleteWhite.png"));
    ui->refreshNotes->setIcon(QIcon(":/icons/refreshWhite.png"));

    // Status bar setup
    word_count_display->setStyleSheet(wc_display_style);
    QString wc = QString("Words: %1").arg(word_count);
    word_count_display->setFrameStyle(QFrame::NoFrame|QFrame::Plain);
    word_count_display->setText(wc);
    word_count_display->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    ui->statusbar->addWidget(word_count_display);

    file_name_display->setStyleSheet(wc_display_style);
    QFileInfo fi(currentFile);
    file_name_display->setText(fi.baseName());
    file_name_display->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    ui->statusbar->addWidget(file_name_display);

    find_label->setStyleSheet(wc_display_style);
    find_label->setText("Find:");
    find_label->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    ui->statusbar->addPermanentWidget(find_label);

    find_bar->setStyleSheet(find_bar_style);
    find_bar->setPlaceholderText("...");
    find_bar->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    find_bar->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    find_bar->setMaximumWidth(1100);
    ui->statusbar->addPermanentWidget(find_bar);

    connect(find_bar, SIGNAL(returnPressed()), this, SLOT(findText()));

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Create unique custom menu for synList
    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showSynListContextMenu(const QPoint &)));

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Add notes list to side_widget
    sidePanelNoteList = new QWidgetListWidget(nullptr, true, QBoxLayout::Direction::TopToBottom);
    sidePanelNoteList->setAcceptDrops(true);
    scroll_list2 = new QWidgetScrollListWidget(sidePanelNoteList);
    ui->listLayout->addWidget(scroll_list2);

    QPalette palette_side_panel;
    palette_side_panel.setColor(QPalette::Window, QColor(50,50,50));
    palette_side_panel.setColor(QPalette::Base, QColor(50,50,50));
    palette_side_panel.setColor(QPalette::Text, QColor(170, 132, 0));
    palette_side_panel.setColor(QPalette::Button, QColor(100,100,100));
    sidePanelNoteList->setPalette(palette_side_panel);

    ////////////////////////////////////////////////////////////////////////////////
    //
    // SQL Setup

    // default and user directory strings need to be dealt with here
    // for now:
    defaultDbDirectory = "D:/Qt/TextEditor/";
    QString init_defaultDB = defaultDbDirectory.append(defaultDBName);
    userDbDir = settings.value("userDBDir", init_defaultDB).toString();
    currentDbDir = settings.value("currentDBDir", init_defaultDB).toString();
    QDir dir;
    dir.setCurrent(init_defaultDB);
    //qDebug() << dir.current();

    try
    {
        if (currentDbDir.isEmpty()) //NotesDb has not been created.
        {
            qDebug() << "inside currentDbDir is empty, " << useDefaultDbDirectory;
            QSqlDatabase notesDB;
            openNotesDbConn(notesDB, init_defaultDB);
            createDbTables(notesDB);
            if (!useDefaultDbDirectory)
                currentDbDir = userDbDir;
            else
                currentDbDir = defaultDbDirectory;
        }

        else    // SQL DB is found:
        {
            //qDebug() << "inside currentDbDir is NOT empty";
            QSqlDatabase notesDB;
            openNotesDbConn(notesDB, currentDbDir);
            //qDebug() << notesDB.tables();
            if (notesDB.tables().isEmpty())
            {
                //qDebug() << "inside notesDB.tables().isEmpty() " << notesDB.tables();
                // display critical message, ask user to confirm creating tables
                QMessageBox msg;
                msg.setText("Selected database is empty. Create new tables for notes?");
                msg.setInformativeText("Do you want to configure this empty Database?");
                msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msg.setDefaultButton(QMessageBox::Cancel);
                bool ok = msg.exec();

                if (ok)
                    createDbTables(notesDB);
                else
                    throw 10;
            }
            else if (!checkDbTables(notesDB))
            {
                // display critical message first, tables mismatch, new db should be created.
                //qDebug() << "inside notesDB is not empty, check tables " << notesDB.tables();
                QMessageBox::warning(this, tr("Table mismatch."),
                                           tr("Please choose another file or create a new databse."));
            }
        }
    }
    catch (int e)
    {
            //qDebug() << "An exception has occured. Exception #" << e << " Failed to initialize Database";
    }

//    QSqlDatabase notesDB;
//    openNotesDbConn(notesDB, defaultDbDirectory);
//    createDbTables(notesDB);
//    addnotesvalues(1, "Chapter-1", "Test note-1");
//    addnotesvalues(2, "Chapter-2", "Test note-2");
//    addnotesvalues(3, "Chapter-3", "Test note-3");
//    addtagvalues(1, 1, "Yil");
//    addtagvalues(1, 2, "Kalti");
//    addtagvalues(2, 1, "Maiden");
//    addtagvalues(2, 2, "University");
//    addtagvalues(3, 1, "hunt");
//    addtagvalues(3, 2, "orphanage");
//    addtagvalues(3, 3, "Yil");

    getLastNoteID();

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Settings

    qRegisterMetaTypeStreamOperators<QList<int> >("QList<int>"); //metatype to store QList in QSettings as QVariant
    noteIDsForSidePanel = settings.value("notes/sidePanelNoteIDs").value<QList<int> >();
    //qDebug() << noteIDsForSidePanel;

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Shortcuts

    QShortcut *shortcutSettings = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_P), this);
    QObject::connect(shortcutSettings, &QShortcut::activated,
                     this, &MainWindow::on_settings_shortcut);

    QShortcut *shortcutNotes = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_H), this);
    QObject::connect(shortcutNotes, &QShortcut::activated, this, &MainWindow::on_notes_shortcut);

    QShortcut *wordLookup = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this);
    QObject::connect(wordLookup, &QShortcut::activated, this, &MainWindow::on_wordLookup_shortcut);

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this, SLOT(newFile()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this, SLOT(open()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(save()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_D), this, SLOT(insertDivider()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_F), this, SLOT(focusFindLine()));
    new QShortcut(QKeySequence(Qt::Key_F1), this, SLOT(showHelpCard()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_B), this, SLOT(showHideStatusBar()));
}

MainWindow::~MainWindow()
{
    delete ui;
    QSqlDatabase notesDB;
    notesDB.close();
}


////////////////////////////////////////////////////////////////////////////////
//
// SQL Functions

void MainWindow::openNotesDbConn(QSqlDatabase &db, QString &dir)
{
    if (db.isOpen())
        db.removeDatabase(QSqlDatabase::defaultConnection);
    currentDbDir = dir;

    settings.setValue("currentDBDir", currentDbDir);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dir);
    db.open();
    try {
        if (db.tables().isEmpty())
        {
            //qDebug() << "inside notesDB.tables().isEmpty() " << db.tables();
            // display critical message, ask user to confirm creating tables
            QMessageBox msg;
            msg.setText("Selected database is empty. Create new tables for notes?");
            msg.setInformativeText("Do you want to configure this empty Database?");
            msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msg.setDefaultButton(QMessageBox::Cancel);
            bool ok = msg.exec();

            if (ok)
                createDbTables(db);
            else
            {
                throw 10;
            }
        }
        else if (!checkDbTables(db))
        {
            // display critical message first, tables mismatch, new db should be created.
            //qDebug() << "inside notesDB is not empty, check tables " << db.tables();
            QMessageBox::warning(this, tr("Table mismatch."),
                                       tr("Please choose another file or create a new databse."));
        }
    }
    catch (int e)
    {
            qDebug() << "An exception has occured. Exception #" << e << " Failed to initialize Database";
    }
}

void MainWindow::closeNotesDbConn(QSqlDatabase &db)
{
    db.close();
}

void MainWindow::openNewDBConn(QString newDBName)
{
    QSqlDatabase notesDB;
    openNotesDbConn(notesDB, newDBName);

    currentDbDir = newDBName;
}

bool MainWindow::checkDbTables(QSqlDatabase& db)
{
    /*  checks if tables are already created, return if they are.
        db.tables() returns a QStringList of tables in the SQL db in the order below.
        better system to sort the QStringLists first is preferred. */
    //QStringList tables = { "tags", "items", "itemtags" };
    QStringList tables = { "tags", "notes" };
    if (db.tables() != tables)
        return false;
    else
        return true;
}

void MainWindow::createDbTables(QSqlDatabase& db)
{
    //create tags table
    if (!db.open())
        qDebug() << "Problem opening database.";

    QString query_1 = "CREATE TABLE tags ("
                    "note_id integer, "
                    "tag_id integer, "
                    "tag_title MEDIUMTEXT);";
    QSqlQuery qry_1;
    if (!qry_1.exec(query_1))
        qDebug() << "error creating tags table.";

    //create notes talbe
    if (!db.open())
        qDebug() << "Problem opening database.";

    QString query_2 = "CREATE TABLE notes ("
                    "note_id integer, "
                    "note_title MEDIUMTEXT, "
                    "note_content LONGTEXT);";

    QSqlQuery qry_2;
    if (!qry_2.exec(query_2))
        qDebug() << "error creating notes table.";
}

void MainWindow::on_addNote_clicked()
{
    // create the next ID past the maximum ID in sql, cross check with tags db?
    int32_t nextID;
    if (lastNoteID == 0)
    {
        nextID = 1;
        lastNoteID = nextID;
    }
    else
    {
        nextID = getLastNoteID() + 1;
        lastNoteID = nextID;
    }
    noteIDsForSidePanel << nextID;
    //qDebug() << "lastNoteID after push = " << lastNoteID;
    QStringList noteTags;
    sidePanelNoteList->addItem(new NoteSheet(nextID, "", "", noteTags));
    QSqlQuery qry;
    qry.prepare("INSERT INTO notes (note_id, note_title, note_content) "
                "VALUES (?, ?, ?);");
    qry.addBindValue(nextID);
    qry.addBindValue("");
    qry.addBindValue("");
    qry.exec();
}

int32_t MainWindow::getLastNoteID()
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

void MainWindow::on_deleteNote_clicked()
{
    auto itemList = sidePanelNoteList->getSelectedItems();
    for (auto n : itemList)
    {
        sidePanelNoteList->removeItem(n);
        while(noteIDsForSidePanel.contains(n->note_id))
            noteIDsForSidePanel.removeOne(n->note_id);      // one if statement is probably enough but just in case, optimize later is too slow.
    }
}

void MainWindow::loadNotes()
{
    QSqlQuery qry;
    for (auto i : noteIDsForSidePanel)
    {
        qry.prepare("SELECT note_id, note_title, note_content FROM notes WHERE note_id = ?");
        qry.addBindValue(i);
        qry.exec();
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
            //connect(newNote, SIGNAL(noteSheetChanged(int32_t, int, QString)), this, SLOT(on_noteSheet_changed(int32_t, int, QString)));
            sidePanelNoteList->addItem(newNote);
        }
    }
}

void MainWindow::on_saveNotes_clicked()
{
    qRegisterMetaTypeStreamOperators<QList<int> >("QList<int>");
    settings.setValue("notes/sidePanelNoteIDs", QVariant::fromValue(noteIDsForSidePanel));
    for (auto n : sidePanelNoteList->getItems())
        if (n->isChanged)
            n->saveNote();
    /*
     * QSettings::setValue() needs QVariant as a second parameter.
     * To pass QList as QVariant, you have to declare it as a Qt meta type.
    */

}

void MainWindow::on_refreshNotes_clicked()
{
    sidePanelNoteList->clear();
    loadNotes();
}

void MainWindow::getNoteForSidePanel(NoteSheet* n)
{
    if (!noteIDsForSidePanel.contains(n->note_id))
        sidePanelNoteList->addItem(n);
    noteIDsForSidePanel.append(n->note_id);
    on_refreshNotes_clicked();
}

void MainWindow::addnotesvalues(int id, QString title, QString content)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO notes ("
                "note_id,"
                "note_title,"
                "note_content)"
                "VALUES (?, ?, ?);");
    qry.addBindValue(id);
    qry.addBindValue(title);
    qry.addBindValue(content);

    if (!qry.exec())
        qDebug() << "error adding values.";
}

void MainWindow::addtagvalues(int noteID, int tagID, QString title)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO tags ("
                "note_id,"
                "tag_id,"
                "tag_title)"
                "VALUES (?, ?, ?);");
    qry.addBindValue(noteID);
    qry.addBindValue(tagID);
    qry.addBindValue(title);

    if (!qry.exec())
        qDebug() << "error adding values.";
}


////////////////////////////////////////////////////////////////////////////////
//
// Datamuse Functions
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit customContextMenuRequested(event->pos());
}

void MainWindow::showSynListContextMenu(const QPoint &pos)
{
    if (txtCur.hasSelection())
    {
        QMenu *synList = new QMenu;
        QString  menuStyle(
                   "QMenu {"
                   "margin: 2px;"
                   "border: 1px solid black;"
                   "menu-scrollable: 1;"
                   "max-height: 435px"
                   "}"
                   "QMenu::scroller{"
                   "menu-scrollable: 1;"
                   "height: 100px;"
                   "}"
                   "QMenu::item{"
                   "background-color: rgb(94, 89, 89);"
                   "color: rgb(255, 255, 255);"
                   "}"
                   "QMenu::item:selected{"
                   "background-color: rgb(145, 141, 141);"
                   "color: rgb(255, 255, 255);"
                   "}"
                );
        synList->setStyleSheet(menuStyle);
        Datamuse word(txtSelected);
        for (auto i : word.returnSynList())
        {
            QAction *newAct = new QAction(i, this);
            synList->addAction(i);
            //synList->addSeparator();
        }
        synList->move(ui->textEdit->mapToGlobal(pos));
        synList->show();

        connect(synList, &QMenu::triggered, [&](QAction* action){
            QString r = action->text();
            qDebug() << r;
            txtCur.insertText(r);
        });
    }
}

void MainWindow::on_textEdit_selectionChanged()
/* Capturing the signal to indicate when text is selected by user.
 * Selected text is stored in txtSelected, non-const.
 * QListView will be used as it is more versatile with fetching data...
 * ...using canFetchMore and fetchMore.
 * Use QMenu for the context menu.
 */
{
    txtCur = ui->textEdit->textCursor();
    txtCur.selectionStart();
    txtCur.selectionEnd();
    txtSelected = txtCur.selectedText();
    //qDebug() << txtSelected;
    //qDebug() << txtcur.hasSelection();
}

////////////////////////////////////////////////////////////////////////////////
//
// File management

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    if (maybeSave())
    {
        saveSettings();
        event->accept();
    }
    else
        event->ignore();
}

// These functions were modelled after the official QT example on their website

void MainWindow::setCurrentFile(const QString &fileName)
{
    /*
     * The setCurrentFile() function is called to reset the state of a few variables when a file is loaded or saved,
     * or when the user starts editing a new file (in which case fileName is empty).
     * We update the curFile variable, clear the QTextDocument::modified flag and the associated QWidget:windowModified flag,
     * and update the window title to contain the new file name (or untitled.txt).
     */
    currentFile = fileName;
    ui->textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = currentFile;
    if (currentFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}

bool MainWindow::saveFile(const QString &fileName)
{
    saveSettings();
    //qDebug() << "saveFile() - fileName: " << fileName;
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return false;
    }
    currentFile = fileName;
    file_name_display->clear();
    file_name_display->setText(currentFile);
    file_name_display->update();
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
    /*
     * In loadFile(), we use QFile and QTextStream to read in the data.
     * The QFile object provides access to the bytes stored in a file.
     * We start by opening the file in read-only mode.
     * The QFile::Text flag indicates that the file is a text file, not a binary file.
     */
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    //If we successfully opened the file, we use a QTextStream object to read in the data.
    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    //if the in.readAll() is taking a long time, use an ifndef QT_NO_CURSOR call to Qt::WaitCursor.
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);

}

bool MainWindow::save()
{
    qDebug() << "save() - currentFile: " << currentFile;
    if (currentFile.isEmpty())
    {
        return saveAs();
    }
    else
    {
        return saveFile(currentFile);
    }
}

bool MainWindow::saveAs()
{
    QFileDialog dialog(this, "Save file");
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setDefaultSuffix("txt");
    QString filter = "Text Files (*.txt)";
    QString fileName = dialog.getSaveFileName(this, "Save file", "", filter, &filter);
//    if (dialog.getSaveFileName(this, "Save file", "", filter, &filter) != QDialog::Accepted)
//        return false;
    currentFile = fileName;
    return saveFile(fileName);

}

bool MainWindow::maybeSave()
{
    /* The maybeSave() function is called to save pending changes.
     * If there are pending changes, it pops up a QMessageBox giving the user to save the document.
     */
    if (!this->ui->textEdit->document()->isModified())
        return true;
    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Application"),
                                   tr("The document has been modified.\n"
                                   "Do you want to save your changes?"),
                                 QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch(ret)
    {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    case QMessageBox::Discard:
        return true;
    default:
        break;
    }
    return true;
}

void MainWindow::newFile()
{
    if (maybeSave())
    {
        ui->textEdit->clear();
        setCurrentFile(QString());
    }
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file:" + file.errorString());
        return;
    }
    loadSettings();
    setWindowTitle(filename);
    QTextStream in(&file);          //set up text stream for file object we created
    QString text = in.readAll();    //read in all the text
    ui ->textEdit->setText(text);   //set the text to the widget
    file.close();
    file_name_display->clear();
    file_name_display->setText(currentFile);
    file_name_display->update();
    /*
    if(maybeSave())
    {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
    */
}

void MainWindow::openPrevious(const QString &filename)
{
    QFile file(filename);
    currentFile = filename;
//    if(!file.open(QIODevice::ReadOnly | QFile::Text))
//    {
//        QMessageBox::warning(this, "Warning", "Cannot open file:" + file.errorString());
//        return;
//    }
    loadSettings();
    setWindowTitle(filename);
    QTextStream in(&file);          //set up text stream for file object we created
    QString text = in.readAll();    //read in all the text
    ui ->textEdit->setText(text);   //set the text to the widget
    file.close();
    file_name_display->clear();
    file_name_display->setText(currentFile);
    file_name_display->update();
}

void MainWindow::documentWasModified()
{
    setWindowModified(this->ui->textEdit->document()->isModified());
}

////////////////////////////////////////////////////////////////////////////////
//
// Setting Functions

void MainWindow::on_settings_shortcut()
{
    QPalette temp_palette = ui->textEdit->palette();
    QColor c_bg = temp_palette.color(QPalette::Base);
    QColor c_t  = temp_palette.color(QPalette::Text);
    //int bgC = c_bg.rgb();
    //int textC = c_t.rgb();  // these are used to set the color buttons when opening settings dialog.
    Settings* settingsDialogue = new Settings(nullptr, c_bg, c_t);
    connect(settingsDialogue, SIGNAL(changeBackgroundColor(QColor)),    this, SLOT(changeBackgroundColor(QColor)));
    connect(settingsDialogue, SIGNAL(changeTextColor(QColor)),          this, SLOT(changeTextColor(QColor)));
    connect(settingsDialogue, SIGNAL(changeTextFont(QFont)),            this, SLOT(changeTextFont(QFont)));
    connect(settingsDialogue, SIGNAL(changeTextSize(int)),              this, SLOT(changeTextSize(int)));
    connect(settingsDialogue, SIGNAL(changeMargins(QString)),           this, SLOT(changeMargins(QString)));
    connect(settingsDialogue, SIGNAL(divider_changed(QString)),         this, SLOT(changeDivider(QString)));
    settingsDialogue->setModal(true);
    settingsDialogue->exec();
    //settings->update_settings();
}

void MainWindow::changeDivider(const QString new_divider)
{
    divider = new_divider;
}

void MainWindow::changeMargins(const QString &margins)
{
    marginsChangedByUser = true;
    ui->textEdit->setStyleSheet(margins);
    //qDebug() << "textEdit stylesheet: " << ui->textEdit->styleSheet();
    QPalette p;
    p = this->palette();
    p.setColor(QPalette::Base, currentBackgroundColor);
    p.setColor(QPalette::Window, currentWindowColor);
    p.setColor(QPalette::Text, currentTextColor);
//    qDebug() << "currentbgColor: " << currentBackgroundColor;
//    qDebug() << "Palette p: " << p.color(QPalette::Base);
//    qDebug() << "Palette p: " << p.color(QPalette::Text);
//    qDebug() << "Palette p: " << p.color(QPalette::Window);
//    qDebug() << "currentWindowColor: " << currentWindowColor;
    this->setPalette(p);
    //ui->textEdit->repaint();
    //this->repaint();
    //ui->textEdit->repaint();
}

void MainWindow::changeBackgroundColor(const QColor c)
{
    QPalette p;
    p = this->palette();
    currentBackgroundColor = c;
    currentWindowColor = c;
    useDefaultPalette = false;
    p.setColor(QPalette::Base, c);
    p.setColor(QPalette::Window, c);
    p.setColor(QPalette::Text, currentTextColor);
    //ui->textEdit->setPalette(p);
    this->setPalette(p);
    ui->textEdit->setPalette(p);
    this->repaint();
}

void MainWindow::changeTextColor(const QColor c)
{
    QPalette p;
    p = this->palette();
    currentTextColor = c;
    useDefaultPalette = false;
    p.setColor(QPalette::Base, currentBackgroundColor);
    p.setColor(QPalette::Window, currentWindowColor);
    p.setColor(QPalette::Text, c);
    p.setColor(QPalette::WindowText, c);
    ui->textEdit->setPalette(p);
    this->repaint();
}

void MainWindow::changeTextFont(const QFont &f)
{
    currentFont = f;
    this->ui->textEdit->selectAll();
    this->ui->textEdit->setCurrentFont(f);
}

void MainWindow::changeTextSize(const int &index)
{
    currentFontSize = index;
    qDebug() << ui->textEdit->fontPointSize();
    this->ui->textEdit->selectAll();
    this->ui->textEdit->setFontPointSize(index);
}

void MainWindow::on_notes_shortcut()
{
    Notes *n = new Notes;
    connect(n, SIGNAL(sendNotes(NoteSheet*)), this, SLOT(getNoteForSidePanel(NoteSheet*)));
    connect(n, SIGNAL(loadNewDB(QString)), this, SLOT(openNewDBConn(QString)));
    n->setModal(true);
    n->exec();
}

void MainWindow::on_wordLookup_shortcut()
{
    WordLookup *w = new WordLookup;
    w->setModal(true);
    w->exec();
}

void MainWindow::loadSettings()
{
//    QColor c;
//    QPalette p;
//    c.setNamedColor(settings.value("palette/backgroundcolor", defaultBaseColor.rgb()).toString());
//    p.setColor(QPalette::Base, c);

//    c.setNamedColor(settings.value("palette/textcolor", defaultTextColor).toString());
//    p.setColor(QPalette::Text, c);

//    c.setNamedColor(settings.value("palette/buttoncolor", defaultButtonColor.rgb()).toString());
//    p.setColor(QPalette::Button, c);

//    c.setNamedColor(settings.value("palette/windowcolor", defaultWindowColor.rgb()).toString());
//    p.setColor(QPalette::Window, c);

//    useDefaultPalette =  settings.value("palette/usedefault", true).toBool();
//    //this->setPalette(p);

    currentBackgroundColor.setNamedColor(settings.value("colors/currentbackgroundcolor", defaultBaseColor.rgb()).toString());
    currentWindowColor.setNamedColor(settings.value("colors/currentwindowcolor", defaultWindowColor.rgb()).toString());
    currentTextColor.setNamedColor(settings.value("colors/currenttextcolor", defaultTextColor.rgb()).toString());


    currentFont.fromString(settings.value("font/font", defaultFont.toString()).toString());
    currentFontSize = settings.value("font/fontsize", defaultFontSize).toInt();


    marginsChangedByUser = settings.value("margins/usedefault", false).toBool();
    currentMargins = settings.value("margins/currentmargins", defaultMargins).toString();


    //qDebug() << "currentmargins: " << currentMargins;
    changeMargins(currentMargins);

    currentFile = settings.value("currentfile", "untitled.txt").toString();

    divider = settings.value("divider", "").toString();
}

void MainWindow::saveSettings()
{
    QPalette p;
    p = this->palette();
//    settings.setValue("palette", p);
//    settings.setValue("palette/backgroundcolor", p.color(QPalette::Base));
//    settings.setValue("palette/textcolor", p.color(QPalette::Text));
//    settings.setValue("palette/buttoncolor", p.color(QPalette::Button));
//    settings.setValue("palette/windowcolor", p.color(QPalette::Window));
    settings.setValue("colors/currentbackgroundcolor", currentBackgroundColor);
    settings.setValue("colors/currenttextcolor", currentTextColor);
    settings.setValue("colors/currentwindowcolor", currentWindowColor);
    settings.setValue("palette/usedefault", useDefaultPalette);

    settings.setValue("font/font", currentFont);
    settings.setValue("font/fontsize", currentFontSize);

    settings.setValue("margins/usedefault", marginsChangedByUser);
    settings.setValue("margins/currentmargin", currentMargins);

    settings.setValue("divider", divider);
    settings.setValue("currentfile", currentFile);
}

void MainWindow::on_slide_button_clicked()
// to add: animation, transperancy, icon
{
    if (ui->side_panel->isHidden())
    {
        ui->side_panel->show();
        ui->slide_button->setText(">");
    }
    else
    {
        ui->side_panel->hide();
        ui->slide_button->setText("<");
    }
}

void MainWindow::findText()
{
    bool found;
    QString searchString = find_bar->text();
    QTextCursor find_cursor;
    found = ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
    if (!found)
    {
        ui->textEdit->moveCursor(QTextCursor::Start);
        ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
    }
    else
    {
        qDebug() << found;
        ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
        // move the cursor one step to the right to find next word if return is pressed.
        find_cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 1);
    }
}

void MainWindow::focusFindLine()
{
    QTimer::singleShot(0, find_bar, SLOT(setFocus()));
}

void MainWindow::updateWordCount()
{
    word_count = ui->textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"),
                                                   QString::SkipEmptyParts).count();
}

void MainWindow::on_textEdit_textChanged()
{
    updateWordCount();
    QString wc = QString("Words: %1").arg(word_count);
    word_count_display->clear();
    word_count_display->setText(wc);
    word_count_display->update();
}

void MainWindow::insertDivider()
{
    qDebug() << "insertDivider()";
    txtCur.clearSelection();
    txtCur.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
    txtCur.insertText(divider);
}

void MainWindow::showHelpCard()
{
    helpcard *h = new helpcard;
    h->setModal(true);
    h->exec();
}

void MainWindow::showHideStatusBar()
{
    qDebug() << "show/hide status: " << ui->statusbar->isHidden();
    if (ui->statusbar->isHidden())
        ui->statusbar->show();
    else
        ui->statusbar->hide();
}

//---------------------------------------------------------------
/*
void MainWindow::on_actionNew_triggered()
{
    currentFile.clear(); //clears the Qstring in currentFile created in mainwindow.h
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file:" + file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);          //set up text stream for file object we created
    QString text = in.readAll();    //read in all the text
    ui ->textEdit->setText(text);   //set the text to the widget
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as:");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file:" + file.errorString());
        return;
    }
    currentFile = filename;
    setWindowTitle(filename);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
*/


