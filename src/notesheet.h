#ifndef NOTESHEET_H
#define NOTESHEET_H

#include <QWidget>
#include "qwidgetlistitem.h"
#include "QLabel"
#include "QLineEdit"
#include "QTextEdit"
#include "QCheckBox"
#include "QPushButton"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSplitter>

namespace Ui {
class NoteSheet;
}

using namespace cw;
using QWidgetListItem = cw::QWidgetListItem;

class NoteSheet : public QWidgetListItem
{
    Q_OBJECT

public:

    NoteSheet(const int32_t& noteID, const QString& text, const QString& title, const QStringList& noteTags);

    //NoteSheet(const QString& text, const QString& title);

    NoteSheet* clone() const override;

    explicit NoteSheet(QWidget *parent = nullptr);
    //explicit NoteSheet(QWidget *parent = nullptr, QStringList *noteTags = new QStringList);
    ~NoteSheet();

    int32_t note_id;

    QString note_title;

    QString note_content;

    QStringList note_tags;

    bool isChanged;

    QStringList getTags();

    void cleanTagsUI();

    void saveNote() { on_saveNoteButton_clicked(); isChanged = false; }

    void paintEvent(QPaintEvent *pe) override;

protected:

    void HighlightBackground(bool high);

    bool selected = false;

private slots:


    void on_noteTagsUI_itemDoubleClicked(QListWidgetItem *item);

    void on_addTagButton_clicked();

    void on_deleteTagButton_clicked();

    void on_noteTitleUI_textEdited(const QString &arg1);

    void on_noteContentUI_textChanged();

    void on_saveNoteButton_clicked();

    void getLastTagID();

    void on_noteTagsUI_itemActivated(QListWidgetItem *item);

    void on_noteTagsUI_itemChanged(QListWidgetItem *item);

    void on_noteTagsUI_currentTextChanged(const QString &currentText);

signals:
    void noteChanged(bool isChanged);

private:
    Ui::NoteSheet *ui;

    int lastTagID;

    enum Field { title = 1,
                 content,
                 tags };

    int CurrentTagCount;

};

#endif // NOTESHEET_H
