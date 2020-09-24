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
