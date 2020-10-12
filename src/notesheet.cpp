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

#include "notesheet.h"
#include "ui_notesheet.h"
#include <QtGui/qpainter.h>
#include <QtGui/qpixmap.h>


using namespace cw;

struct Grabber : QWidget
   {
      void paintEvent(QPaintEvent* event) override
      {
         QPen pen(QColor(180, 180, 180, 128));
         pen.setWidth(3);

         const int h = height();
         const int w = width();

         QPainter painter(this);
         painter.setPen(pen);
         static constexpr int offset = 4;
         static constexpr int diagonal = 10;
         for (int y = offset; y < h - (offset + diagonal) ; y += diagonal)
         {
            painter.drawLine(0, y, w, y + diagonal);
         }
      }
   };

/* Use textEdited signals to check for changes instead of textChanged because
 * textEdited will only be called when the user makes changes, and won't be called
 * when functions like QLineEdit::setText() are used.
 */


NoteSheet::NoteSheet(const int32_t& noteID, const QString& title, const QString& text, const QStringList& noteTags) :
    ui(new Ui::NoteSheet)
    {
    ui->setupUi(this);

    note_id = noteID;
    note_tags = noteTags;
    note_title = title;
    note_content = text;

    lastTagID = 1;
    getLastTagID();
    //ui->noteIDUI->setNum(noteID);
    ui->noteTitleUI->setText(title);
    ui->noteContentUI->setText(text);
    ui->noteTagsUI->addItems(noteTags);
    ui->noteTagsUI->takeItem(0);    //removes the added empty "" item found at row (0)
    ui->noteTagsUI->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

    //ui->splitter->setSizes(QList<int>({1, 1, 1}));
    setToolTip("note");
    setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));

    ui->saveNoteButton->setIcon(QIcon(":/icons/saveWhite.png"));
    ui->addTagButton->setIcon(QIcon(":/icons/plusWhite.png"));
    ui->deleteTagButton->setIcon(QIcon(":/icons/deleteWhite.png"));

    // Horizontal layout to contain the grabber and the rest of the UI.
//    auto top_layout = new QHBoxLayout;
//    top_layout->setMargin(0);
//    setLayout(top_layout);

    // Grabber to always give some area to grab for drag-and-drop.
    auto handle = new Grabber;
    handle->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred));
    handle->setMinimumSize(QSize(8, 8));
    //ui->verticalLayout->addWidget(handle);

    QString textEditStyle(
                "QTextEdit {"
                "}"
                "QGraphicsView:focus {"
                "border: none;"
                "outline: none;"
                "}"
                );
    ui->noteContentUI->setStyleSheet(textEditStyle);

    QString buttonsStyle(
                "QPushButton {"
                "background: transparent; "
                "text-align: center;"
                "} "
                "QPushButton::pressed {"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                "stop: 0 #dadbde, stop: 1 #f6f7fa);"
                "}");
    ui->addTagButton->setStyleSheet(buttonsStyle);
    ui->deleteTagButton->setStyleSheet(buttonsStyle);
    ui->saveNoteButton->setStyleSheet(buttonsStyle);
    }

// update currentNoteTags if tags are changed.


NoteSheet* NoteSheet::clone() const
    {
    // The clone must duplicate the data.
    //
    // We only need to duplicate the text and check state.
    // Every thing else is constant in our example.
    auto newItem = new NoteSheet(note_id, note_title, note_content, note_tags);
    return newItem;
    }

NoteSheet::~NoteSheet()
{
    delete ui;
}

QStringList NoteSheet::getTags()
{
    QStringList tagsList;
    QListWidgetItem * item;

    // Read all items text and put in a string list
    for(int i = 0; i < ui->noteTagsUI->count(); i++)
    {
    item = ui->noteTagsUI->item(i);
    tagsList << item->text();
    }
    return tagsList;

    isChanged = false;
}

void NoteSheet::on_noteTagsUI_itemDoubleClicked(QListWidgetItem *item)
{
    bool ok;
    item->setText(QInputDialog::getText(this, tr("Enter tag label:"),
                                        tr("Tag label:"), QLineEdit::Normal,
                                        "", &ok));
}

void NoteSheet::on_addTagButton_clicked()
{
    bool ok;
    QString newTag = QInputDialog::getText(this, tr("Enter tag label:"),
                                                      tr("Tag label:"), QLineEdit::Normal,
                                                      "", &ok);
    if (newTag.isEmpty() || newTag.isNull())
    {
        QMessageBox msg;
        msg.setText("Error: empty tag");
        msg.exec();
    }
    else
        ui->noteTagsUI->addItem(newTag);

}

void NoteSheet::on_deleteTagButton_clicked()
{
    ui->noteTagsUI->takeItem(ui->noteTagsUI->currentRow());
}

void NoteSheet::cleanTagsUI()
{
    /* %%% Function not required anymore, it appears that the empty item appears only
     * on row 0 at the start, so removed it when building the UI.
     * %%%
     * This function will clean up the empty tags appearing in the tags ListWidget
     * which mess with the SQL queries. ListWidget moves the item index of all items
     * upwards after a removed item so the number of rows must be updated each loop
     * and the index subtracts when takeItem is called successfully to account for the
     * item shift.
     */
    try {
        int rows = ui->noteTagsUI->count();
        for (int i = 0; i<rows; ++i)
        {
            rows = ui->noteTagsUI->count();
            qDebug() << "1. i before takeItem: " << i;
            auto item = ui->noteTagsUI->item(i);
            qDebug() << "2. item check: " << item->text();
            if (item->text() == "")
            {
                qDebug() << "Item found: " << item->text() << " Hidden status: " << item->isHidden();

                ui->noteTagsUI->takeItem(i);
                qDebug() << "3. i after takeItem: " << i;
                qDebug() << "4. Removal check: " << ui->noteTagsUI->item(i)->text();
                --i;
            }
            throw 20;
        }
        return;
    }  catch (int e) {
        qDebug() << "An exception has occured. Exception #" << e;
    }

}

void NoteSheet::getLastTagID()
{
    QSqlQuery qry;
    qry.prepare("SELECT MAX(tag_id) FROM tags WHERE note_id = ?");
    qry.addBindValue(note_id);
    if (!qry.exec())
        qDebug() << "Could not get last tagID";
    while (qry.next())
    {
        int maxID = qry.value(0).toInt();
        if (lastTagID >= maxID)
            break;
        else
            lastTagID = maxID;
    }
}

void NoteSheet::on_saveNoteButton_clicked()
{
    if (!isChanged)
        return;
    else
    {
        QSqlQuery qry;
        qry.prepare("UPDATE notes SET note_title = ? , note_content = ? WHERE note_id = ? ");
        qry.addBindValue(note_title);
        qry.addBindValue(ui->noteContentUI->toPlainText());
        qry.addBindValue(note_id);
        qDebug() << "qry.boundvalues() " << qry.boundValue(0) << " " << qry.boundValue(1) << " " << qry.boundValue(2);
        qDebug() << "Save button: Title: " << note_title << " note ID: " << note_id;
        qDebug() << "qry last error: " << qry.lastError().text();
        qry.exec();
        //qDebug() << "qry: " << qry.executedQuery();

        int i = 0;  //index
        //cleanTagsUI();
        //qDebug() << ui->noteTagsUI->item(0)->text();
        //qDebug() << ui->noteTagsUI->item(1)->text();
        //qDebug() << ui->noteTagsUI->item(2)->text();
        QList<QListWidgetItem *> items =
                ui->noteTagsUI->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard);  //roundabout way to getItems from QListWidget
        int newTags = items.size();
        int oldTags = note_tags.count();
        qDebug() << "newTags: " << newTags << " oldTags: " << oldTags;

        if (newTags == 0)
        {
            while (i<oldTags)
            {
                qDebug() << "i = " << i;
                qDebug() << "| DELETE | tag_id: " << i;
                QSqlQuery qry;
                qry.prepare("DELETE FROM tags WHERE note_id = ?");
                qry.addBindValue(note_id);
                if (!qry.exec())
                    qDebug() << "Could not get delete tag during save";
                ++i;
            }
            return;
        }

        for (auto t : items)
        {
            qDebug() << "i = " << i;
            if (i <= newTags && i < oldTags)
            {
                qDebug() << "| UPDATE | tag: " << t->text();
                QSqlQuery qry;
                qry.prepare("UPDATE tags SET tag_title = ? WHERE note_id = ? AND tag_id = ? ");
                qry.addBindValue(t->text());
                qry.addBindValue(note_id);
                qry.addBindValue(i+1);
                qDebug() << "BOUND VALUES: " << "tag: " <<  qry.boundValue(0) << " note_id: " << qry.boundValue(1) << " tag_id: " << qry.boundValue(2);
                qry.exec();
            }

            if (i >= oldTags)
            {
                getLastTagID();
                qDebug() << "| INSERT | tag: " << t->text();
                QSqlQuery qry;
                qry.prepare("INSERT INTO tags (note_id, tag_id, tag_title) "
                            "VALUES (?, ?, ?);");
                qry.addBindValue(note_id);
                qry.addBindValue(i+1);
                qry.addBindValue(t->text());
                qDebug() << "BOUND VALUES: note_id: " << qry.boundValue(0) << " tag_id: " << qry.boundValue(1) << " tag: " << qry.boundValue(2);
                qry.exec();
                ++lastTagID;
            }
        ++i;
        }

        if (oldTags > newTags)
        {
            while (i<oldTags)
            {
                qDebug() << "i = " << i;
                qDebug() << "| DELETE | tag_id: " << i;
                QSqlQuery qry;
                qry.prepare("DELETE FROM tags WHERE note_id = ? AND tag_id = ? ");
                qry.addBindValue(note_id);
                qry.addBindValue(i+1);
                qry.exec();
                ++i;
            }
        }
    }
    isChanged = false;
}

// isChanged toggles:

void NoteSheet::on_noteTitleUI_textEdited(const QString &arg1)
{
    note_title = ui->noteTitleUI->text();
    //Field field = title;
    //qDebug() << "title change signal detected.";
    isChanged = true;
    //qDebug() << "isChanged: " << isChanged;
    emit noteChanged(isChanged);
}

void NoteSheet::on_noteContentUI_textChanged()
{
    QString text = ui->noteContentUI->toPlainText();
    isChanged = true;
    //Field field = content;
    //qDebug() << "isChanged: " << isChanged;
    emit noteChanged(isChanged);
}

void NoteSheet::on_noteTagsUI_itemActivated(QListWidgetItem *item)
{
    isChanged = true;
    emit noteChanged(isChanged);
}

void NoteSheet::on_noteTagsUI_itemChanged(QListWidgetItem *item)
{
    isChanged = true;
    emit noteChanged(isChanged);
}

void NoteSheet::on_noteTagsUI_currentTextChanged(const QString &currentText)
{
    isChanged = true;
    emit noteChanged(isChanged);
}

void NoteSheet::paintEvent(QPaintEvent *pe)
/* Added this override function to fix a technicality with stylesheets:
 * "When you don't provide Q_OBJECT, your class has no Meta data,
 * and hence is considered as a QWidget."
 */
{
  QStyleOption o;
  o.initFrom(this);
  QPainter p(this);
  style()->drawPrimitive(
    QStyle::PE_Widget, &o, &p, this);
};
