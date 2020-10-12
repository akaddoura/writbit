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

#ifndef QT_ADDITIONS_QWIDGET_SCROLL_LIST_WIDGET_H
#define QT_ADDITIONS_QWIDGET_SCROLL_LIST_WIDGET_H

#include <QtWidgets/qscrollarea.h>

class QWidget;

namespace cw
{
   /////////////////////////////////////////////////////////////////////////
   //
   // Scrollable widget.
   //
   // Use it to wrap the QWidgetListWidget to provide a scrollable list.
   // The list widget is not scrollable by itself so that it can be embedded
   // within its own items if needed to provide recursive lists.

   struct QWidgetScrollListWidget : public QScrollArea
   {
      // Create a scrollable widget around another widget.
      QWidgetScrollListWidget(QWidget * widget, QWidget* parent = nullptr);
   };
}

#endif
