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

#ifndef NOTES_H
#define NOTES_H

#include <QDialog>
#include <QSql>
#include <QListWidgetItem>
#include <QDialogButtonBox>
#include <QFileDialog>

#include <qwidgetscrolllistwidget.h>
#include <qwidgetlistwidget.h>
#include <notesheet.h>
#include <qwidgetlistitem.h>


namespace Ui {
class notes;

}

using namespace cw;

class Notes : public QDialog
{
    Q_OBJECT

    using QWidgetScrollListWidget   = cw::QWidgetScrollListWidget;
    using QWidgetListWidget         = cw::QWidgetListWidget;

public:
    explicit Notes(QWidget *parent = nullptr);

    QString currentDBName;
    ~Notes();

signals:
    void sendNotes(NoteSheet*);
    void loadNewDB(QString dbName);
//std::vector<NoteSheet *, std::allocator<NoteSheet *>>
protected:
    void buildUI();

    void connectUI();

    void loadNotes();

    void saveNoteChanges();

    int32_t getLastNoteID();

    void getTotalNotesCount();

    QWidgetListWidget* list1 = nullptr;
    QWidgetScrollListWidget* scroll_list1 = nullptr;

private slots:
    void on_addNoteButton_clicked();

    void on_tagsList_itemClicked(QListWidgetItem *item);

    void on_removeNoteButton_clicked();

    void on_notesSearchBar_textChanged(const QString &arg1);

    void on_refreshButton_clicked();

    void on_updateDatabase_clicked();

    void noteSheetChanged(bool isChanged);

    void on_sendToSidePanel_clicked();

    void on_loadDatabase_clicked();

    void on_newDatabase_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

    void checkToSave();

    void on_buttonBox_accepted();

    QStringList getCurrentTags();

private:
    Ui::notes *ui;

    void loadTags();

    int32_t lastNoteID;

    int32_t CurrentIDCount;

    int notesCount;

    bool maybeSave {false};

};

#endif // NOTES_H
