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

#include "qwidgetscrolllistwidget.h"
#include "qwidgetlistitem.h"
#include "qwidgetlistwidget.h"
#include "QWidgetListMimeData.h"

namespace cw
{
   QWidgetScrollListWidget::QWidgetScrollListWidget(QWidget* widget, QWidget* parent)
   : QScrollArea(parent)
   {
      setWidget(widget);

      bool isVertical = true;
      if (auto list = dynamic_cast<QWidgetListWidget*>(widget))
         if (!list->isVertical())
            isVertical = false;

      if (isVertical)
      {
         setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));
      }
      else
      {
         setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
         setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
         setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum));
      }

      setWidgetResizable(true);
      setSizeAdjustPolicy(SizeAdjustPolicy::AdjustToContents);
   }

}

