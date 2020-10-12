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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "ui_settings.h"
#include "mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <QSettings>
#include <QScreen>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    ~Settings();

    explicit Settings(QWidget *parent = nullptr, QColor bgC = nullptr, QColor textC = nullptr);

    bool typewriterSounds();
    bool showPages();
    bool showWords();

    void setPagecount(bool flag);


signals:
    void changeBackgroundColor(QColor c);
    void changeTextColor(QColor c);
    void changeTextFont(const QFont &f);
    void changeTextSize(const int index);
    void changeMargins(const QString margin);
    void divider_changed(const QString &arg1);

public slots:
    //void update_settings();

private slots:

    void on_bgColor_clicked();

    void on_textColor_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_comboBox_currentIndexChanged(int index);

    void on_setMarginExactWidth_clicked();

    void on_setMarginsSize_clicked();

    void on_setMarginsBook_clicked(bool checked);

    void on_dividerLineEdit_textEdited(const QString &arg1);

    void on_setMarginsScreenWidth_clicked();

    void on_marginsExactWidthPref_returnPressed();

    void on_marginsSizePref_returnPressed();

private:
    Ui::Settings *ui;
    QSettings settings;

    void reload();
    void write();

    int pageCount;
    int wordCount;
    int bgColor;
    int textColor;
    QPalette p;

    QRect screenGeometery;

    double marginsExactWidth;
    int marginsSize;
    int marginsBook;
    int lastRadioButton;

    QColor defaultWindowColor = QColor(50,50,50);
    QColor defaultBaseColor = QColor(31,31,31);
    QColor defaultTextColor = QColor(170, 132, 0);
};

#endif // SETTINGS_H
