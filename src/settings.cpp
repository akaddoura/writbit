#include "settings.h"


Settings::Settings(QWidget *parent, QColor bgC, QColor textC) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

   // paint buttons as neccessary.

    this->setWindowFlags(Qt::Popup);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);

    ui->comboBox->setCurrentIndex(5);

    QScreen *screen = QGuiApplication::primaryScreen();
    screenGeometery = screen->geometry();
    ui->marginsExactWidthPref->setValidator(new QIntValidator(0, screenGeometery.width(), this)); // set limit to variable

    QSettings settings;
    QString divider = settings.value("divider", "").toString();
    ui->dividerLineEdit->setText(divider);

    ui->marginsExactWidthPref->setText(settings.value("margins/exactwidth", QString::number(80)).toString());
    ui->marginsSizePref->setText(settings.value("margins/marginsize", 150).toString());

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(50,50,50));
    palette.setColor(QPalette::Base, QColor(50,50,50));
    palette.setColor(QPalette::Text, QColor(255, 255, 255));
    palette.setColor(QPalette::Button, QColor(100,100,100));

    this->setPalette(palette);
    ui->settingsDialog->setPalette(palette);

    QString  tabWidgetStyle(
               "QToolBox {"
               "background-color: rgb(90,90,90);"
               "color: white;"
               "}"
               "QToolBox::tab {"
               "background-color: rgb(90,90,90);"
               "color: black;"
               "border-bottom: 1px solid;"
               "border-top: none;"
               "border-right: none;"
               "border-left: none;"
               "border-color: white;"
               "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
               "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
               "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
               "}");

   ui->settingsDialog->setStyleSheet(tabWidgetStyle);
   //ui->EditorTab->setStyleSheet(tabWidgetStyle);

    QColor c = bgC;
    QString cs_bg;
    QTextStream(&cs_bg) << c.red() << "," << c.green() << "," << c.blue();
    QString s1 = QString("background : rgb(%1); ").arg(cs_bg);
    ui->bgColor->setStyleSheet(s1);
    repaint();

    QColor c2 = textC;
    QString cs_text;
    QTextStream(&cs_text) << c2.red() << "," << c2.green() << "," << c2.blue();
    QString s2 = QString("background : rgb(%1); ").arg(cs_text);
    ui->textColor->setStyleSheet(s2);
    repaint();

    if (lastRadioButton != 0)
    {
        lastRadioButton = settings.value("margins/lastbutton", 1).toInt();
        switch (lastRadioButton)
        {
        case 1:
            ui->setMarginExactWidth->setChecked(true);
            break;
        case 2:
            ui->setMarginsSize->setChecked(true);
            break;
        case 3:
            ui->setMarginsScreenWidth->setChecked(true);
        }
    }
}


Settings::~Settings()
{
    qDebug() << "Setting deleted";
    delete ui;
}

void Settings::reload()
// function to be implemented.
{
    //bgColor = settings.value("Style/background_color", -16777216).toInt();     //default is QRgb int (not unsigned) for black.

    // session-end note: type conflict, store rgb setting as int and try again.
}

void Settings::on_bgColor_clicked()
{
    bgColor = QColorDialog::getColor(QColor(35,35,35), this).rgb();
    QColor c;
    c.setRgb(bgColor);
//    p.setColor(QPalette::Base, c);
//    p.setColor(QPalette::Window, c);
//    //p.setColor(QPalette::Button, bg_color);
    emit changeBackgroundColor(c);

    QString cs;
    QTextStream(&cs) << c.red() << "," << c.green() << "," << c.blue();
    QString s = QString("background : rgb(%1) ").arg(cs);
    ui->bgColor->setStyleSheet(s);
    repaint();
}

void Settings::on_fontComboBox_currentFontChanged(const QFont &f)
{
    emit changeTextFont(f);
}

void Settings::on_comboBox_currentIndexChanged(int index)
{
    emit changeTextSize(index);
}

void Settings::on_textColor_clicked()
{
    textColor = QColorDialog::getColor(QColor(170,132,0), this).rgb();
    QColor c;
    c.setRgb(textColor);
    emit changeTextColor(c);

    QString cs;
    QTextStream(&cs) << c.red() << "," << c.green() << "," << c.blue();
    QString s = QString("background : rgb(%1) ").arg(cs);
    ui->textColor->setStyleSheet(s);
    repaint();
}

void Settings::on_setMarginExactWidth_clicked()
{
    lastRadioButton = 1;
    settings.setValue("margins/lastbutton", lastRadioButton);
    //qDebug() << "exact width clicked";
    double width = screenGeometery.width();
    //qDebug() << width;
    marginsExactWidth = ui->marginsExactWidthPref->text().toDouble();
    if (marginsExactWidth > 90)
        marginsExactWidth = 90;
    else if (marginsExactWidth < 50)
            marginsExactWidth = 50;
    //qDebug() << "marginsExactWidth: " << marginsExactWidth;
    double actualExactWidth = width * (marginsExactWidth/100);
    //qDebug() << "actualExactWidth: " << actualExactWidth;
    double actualMarginsWidth = (width - actualExactWidth)/2;
    //qDebug() << "actualMarginsWidth: " << actualMarginsWidth;
    settings.setValue("margins/exactwidth", marginsExactWidth);
    QString s = QString("QTextEdit { "
                        "margin-right: %1px; "
                        "margin-left: %1px } ").arg(QString::number(actualMarginsWidth));
    emit changeMargins(s);
}

void Settings::on_setMarginsSize_clicked()
{
    lastRadioButton = 2;
    settings.setValue("margins/lastbutton", lastRadioButton);
    marginsSize = ui->marginsSizePref->text().toInt();
    if (marginsSize > 480)
        marginsSize = 480;
    else if (marginsSize < 0)
        marginsSize = 0;
    //qDebug() << "marginsSize: " << marginsSize;
    settings.setValue("margins/marginsize", marginsSize);
    QString s = QString("QTextEdit { "
                        "margin-right: %1px; "
                        "margin-left: %1px } ").arg(QString::number(marginsSize));
    emit changeMargins(s);
}

void Settings::on_setMarginsBook_clicked(bool checked)
{
//    qDebug() << "radio clicked";
//    int width = screenGeometery.width();
//    marginsBook = ui->marginsBook->text().toInt();
//    if (marginsSize > width)
//        marginsSize = 1;
//    qDebug() << "marginsSize: " << marginsSize;
//    QString s = QString("QTextEdit { "
//                        "margin-right: %1px; "
//                        "margin-left: %1px } ").arg(QString::number(marginsBook));
//    emit changeMarginToExactWidth(s);
}


void Settings::on_dividerLineEdit_textEdited(const QString &arg1)
{
    emit divider_changed(arg1);
}

void Settings::on_setMarginsScreenWidth_clicked()
{
    lastRadioButton = 3;
    settings.setValue("margins/lastbutton", lastRadioButton);
    QString s = QString("");
    emit changeMargins(s);
}

void Settings::on_marginsExactWidthPref_returnPressed()
{
    ui->setMarginExactWidth->click();
}

void Settings::on_marginsSizePref_returnPressed()
{
    ui->setMarginsSize->click();
}
