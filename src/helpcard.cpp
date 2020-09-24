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
