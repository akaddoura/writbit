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

#include "helpcard.h"
#include "ui_helpcard.h"

helpcard::helpcard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpcard)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(50,50,50));
    palette.setColor(QPalette::Base, QColor(50,50,50));
    palette.setColor(QPalette::Text, QColor(255, 255, 255));
    palette.setColor(QPalette::Button, QColor(255,255,255));

    this->setPalette(palette);

    this->setWindowFlags(Qt::Popup);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
}

helpcard::~helpcard()
{
    delete ui;
}
