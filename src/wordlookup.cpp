#include "wordlookup.h"
#include "ui_wordlookup.h"

WordLookup::WordLookup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wordLookup)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(50,50,50));
    palette.setColor(QPalette::Base, QColor(50,50,50));
    palette.setColor(QPalette::Text, QColor(255, 255, 255));
    palette.setColor(QPalette::Button, QColor(100,100,100));

    this->setPalette(palette);
}

WordLookup::~WordLookup()
{
    delete ui;
}

void WordLookup::on_optionBox1_activated(int index)
{
    _option1 = index;
}

void WordLookup::on_optionBox2_activated(int index)
{
    _option2 = index;
}

void WordLookup::on_optionBox3_activated(int index)
{
    _option3 = index;
}

void WordLookup::on_subSearchBar1_textEdited(const QString &arg1)
{
    _option1Text = arg1;
}

void WordLookup::on_subSearchBar2_textEdited(const QString &arg1)
{
    _option2Text = arg1;
}

void WordLookup::on_subSearchBar3_textEdited(const QString &arg1)
{
    _option3Text = arg1;
}

void WordLookup::on_searchButton_clicked()
{
    QStringList wordList;
    Datamuse search(_option1, _option2, _option3, _option1Text, _option2Text, _option3Text);
    for (auto i : search.returnSynList())
    {
        wordList << i;
    }
    QStringListModel* m = new QStringListModel(wordList);
    ui->resultsView->setModel(m);
}
