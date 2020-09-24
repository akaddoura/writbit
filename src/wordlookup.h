#ifndef WORDLOOKUP_H
#define WORDLOOKUP_H

#include <QDialog>
#include "datamuse.h"

namespace Ui {
class wordLookup;
}

class WordLookup : public QDialog
{
    Q_OBJECT

public:
    explicit WordLookup(QWidget *parent = nullptr);
    ~WordLookup();

private slots:


    void on_optionBox1_activated(int index);

    void on_optionBox2_activated(int index);

    void on_optionBox3_activated(int index);

    void on_subSearchBar1_textEdited(const QString &arg1);

    void on_subSearchBar2_textEdited(const QString &arg1);

    void on_subSearchBar3_textEdited(const QString &arg1);

    void on_searchButton_clicked();

private:
    Ui::wordLookup *ui;

    int _option1;
    int _option2;
    int _option3;

    QString _option1Text;
    QString _option2Text;
    QString _option3Text;

    QString _mainSearchText;
};

#endif // WORDLOOKUP_H
