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

//void WordLookup::on_optionBox2_activated(int index)
//{
//    _option2 = index;
//}

//void WordLookup::on_optionBox3_activated(int index)
//{
//    _option3 = index;
//}

void WordLookup::on_subSearchBar1_textEdited(const QString &arg1)
{
    _option1Text = arg1;
}

//void WordLookup::on_subSearchBar2_textEdited(const QString &arg1)
//{
//    _option2Text = arg1;
//}

//void WordLookup::on_subSearchBar3_textEdited(const QString &arg1)
//{
//    _option3Text = arg1;
//}

void WordLookup::on_searchButton_clicked()
{
    QStringList wordList;
    //Datamuse search(_option1, _option2, _option3, _option1Text, _option2Text, _option3Text);
    Datamuse search(_option1, _option1Text);
    for (auto i : search.returnSynList())
    {
        wordList << i;
    }
    QStringListModel* m = new QStringListModel(wordList);
    ui->resultsView->setModel(m);
}
