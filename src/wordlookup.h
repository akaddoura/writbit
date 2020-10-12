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

    //void on_optionBox2_activated(int index);

    //void on_optionBox3_activated(int index);

    void on_subSearchBar1_textEdited(const QString &arg1);

    //void on_subSearchBar2_textEdited(const QString &arg1);

    //void on_subSearchBar3_textEdited(const QString &arg1);

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
