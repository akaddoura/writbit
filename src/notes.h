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
