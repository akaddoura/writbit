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

#ifndef HELPCARD_H
#define HELPCARD_H

#include <QDialog>

namespace Ui {
class helpcard;
}

class helpcard : public QDialog
{
    Q_OBJECT

public:
    explicit helpcard(QWidget *parent = nullptr);
    ~helpcard();

private:
    Ui::helpcard *ui;
};

#endif // HELPCARD_H
