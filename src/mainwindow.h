#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QShortcut>
#include <QSettings>
#include <QCloseEvent>
#include <QSaveFile>
#include <QGraphicsAnchorLayout>
#include <QLayout>
#include <QListWidget>
#include <QMenu>
#include <QTimer>
#include <QtSql>
#include <QGraphicsOpacityEffect>
#include <QList>
#include <QMetaType>
#include <QVariant>
#include <QPainter>

#include <qwidgetscrolllistwidget.h>
#include <qwidgetlistwidget.h>
#include <notesheet.h>
#include <qwidgetlistitem.h>
#include "settings.h"
#include "notes.h"
#include "datamuse.h"
#include "wordlookup.h"
#include "helpcard.h"
#include <qwidgetscrolllistwidget.h>
#include <qwidgetlistwidget.h>
#include <notesheet.h>
#include <qwidgetlistitem.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
using namespace cw;
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~MainWindow();

    MainWindow(QWidget *parent = nullptr);

    //MainWindow(const QString& id);

    QString dbName;

    void openNotesDbConn(QSqlDatabase& db, QString& dir);
    void closeNotesDbConn(QSqlDatabase &db);
    void createDbTables(QSqlDatabase& db);
    bool checkDbTables(QSqlDatabase& db);
    void addnotesvalues(int id, QString title, QString content);    // obsolete func for testing purposes
    void addtagvalues(int noteID, int tagID, QString title);        // obsolete func for testing purposes

    void loadFile(const QString &fileName);

    QLabel      *word_count_display = new QLabel(this);
    QLabel      *file_name_display  = new QLabel(this);
    QLineEdit   *find_bar           = new QLineEdit(this);
    QLabel      *find_label         = new QLabel(this);

    //void paintEvent(QPaintEvent *pe) override;

protected:
    void loadSettings();
    void saveSettings();

    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void closeEvent(QCloseEvent *event) override;

    // Datamuse synList event
    void mouseDoubleClickEvent(QMouseEvent* event) override;

    // Side panel notes system
    int32_t getLastNoteID();
    void getTotalNotesCount();
    QWidgetListWidget* sidePanelNoteList = nullptr;
    QWidgetScrollListWidget* scroll_list2 = nullptr;

    void updateWordCount();

private slots:

    // File management
    void newFile();
    void open();
    void openPrevious(const QString &filename);
    bool save();
    bool saveAs();
    void documentWasModified();

    //Shortcuts
    void on_settings_shortcut();
    void on_notes_shortcut();
    void on_wordLookup_shortcut();

    // Setting funcs
    void changeBackgroundColor(const QColor c);
    void changeTextColor(const QColor c);
    void changeTextFont(const QFont &f);
    void changeTextSize(const int &index);
    void changeMargins(const QString &margins);

    // Divider
    void changeDivider(const QString new_divider);
    void insertDivider();

    // Notes
    void getNoteForSidePanel(NoteSheet* n);
    void on_slide_button_clicked();
    void openNewDBConn(QString newDBName);
    void on_addNote_clicked();
    void on_deleteNote_clicked();
    void on_refreshNotes_clicked();
    void loadNotes();
    void on_saveNotes_clicked();

    // Datamuse synonyms
    void on_textEdit_selectionChanged();
    void showSynListContextMenu(const QPoint &pos);

    // word count
    void on_textEdit_textChanged();

    // help card
    void showHelpCard();

    // find text
    void findText();
    void focusFindLine();

    // status bar
    void showHideStatusBar();

private:
    Ui::MainWindow *ui;     //points to UI class

    QSettings settings;

    QString currentFile;    //holds name of current file entered by user

    //QPalette p;

    QColor defaultWindowColor = QColor(31,31,31);
    QColor defaultBaseColor   = QColor(31,31,31);
    QColor defaultTextColor   = QColor(170,132,0);
    QColor defaultButtonColor = QColor(100,100,100);  
    QString defaultMargins = QString("QTextEdit { "
                                      "margin-right:    330px; "
                                      "margin-left:     330px; "
                                      "}");

    QFont defaultFont;
    int defaultFontSize = 12;

    QColor currentBackgroundColor;
    QColor currentTextColor;
    QColor currentWindowColor;
    int currentFontSize;
    QString currentMargins;
    QFont currentFont;

    QTextCursor txtCur;

    QString txtSelected;

    QString divider;

    int word_count;

    bool marginsChangedByUser = false;

    bool useDefaultPalette = true;



    ///////////////////////////////////////
    //
    // Notes

    void loadTags();

    int32_t lastNoteID {};

    int32_t CurrentIDCount;

    int notesCount;

    QList<int32_t> noteIDsForSidePanel;

    QString defaultDbDirectory;

    QString userDbDir;

    QString defaultDBName { "notes.sqlite" };

    bool useDefaultDbDirectory;

    QString currentDbDir;

    bool checkDbDir;

    QString currentDbName;

};
#endif // MAINWINDOW_H
