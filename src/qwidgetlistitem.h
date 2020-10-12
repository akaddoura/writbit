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
 *
 * Thanks to pierrebai on github for creating the original version of this
 * widget to contain a list of widgets inside it.
 ***********************************************************************/

#pragma once

#ifndef QT_ADDITIONS_QWIDGET_LIST_ITEM_H
#define QT_ADDITIONS_QWIDGET_LIST_ITEM_H

#include <QtWidgets/qwidget.h>


namespace cw
{
   /////////////////////////////////////////////////////////////////////////
   //
   // Complex widget kept in a list widget.

struct QWidgetListItem : QWidget
{
  // Create an item.
  QWidgetListItem(QWidget* parent = nullptr);
  ~QWidgetListItem();

  // Selection.
  bool isSelected() const { return _selected; }
  void select(bool sel) { _selected = sel; update(); }

  // Item cloning for drag-and-drop.
  virtual QWidgetListItem* clone() const;

protected:
  // Used to draw highlights.
  void enterEvent(QEvent* event) override;
  void leaveEvent(QEvent* event) override;

  void HighlightBackground(bool high);

  bool _selected = false;

  Q_OBJECT;
};
}

#endif
