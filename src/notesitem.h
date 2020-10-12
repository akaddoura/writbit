#ifndef NOTESITEM_H
#define NOTESITEM_H

#include <QAbstractItemModel>
#include "qwidgetlistitem.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>

using QWidgetListItem = cw::QWidgetListItem;

struct notesitem : public cw::QWidgetListItem
{
   notesitem(const QString& text, bool isChecked = false);

   notesitem* clone() const override;

private:
   QLabel* namelabel = nullptr;
   QLineEdit* textEdit = nullptr;
   QPushButton* editButton = nullptr;
   QCheckBox* include = nullptr;

};

#endif // NOTESITEM_H
