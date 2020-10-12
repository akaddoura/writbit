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

#include <qwidgetlistitem.h>

#include <mutex>

namespace cw
{
   using namespace std;

   namespace
   {
      QPalette _DefaultBackground;
      QPalette _HighBackground;
      QPalette _SelectedBackground;

      once_flag initPalettes;

      static vector<QWidgetListItem*> _HighlightedItems;
   }

   QWidgetListItem::QWidgetListItem(QWidget* parent)
   : QWidget(parent)
   {
      setBackgroundRole(QPalette::ColorRole::Base);
      setAutoFillBackground(true);

      call_once(initPalettes, [self = this]()
      {
         _DefaultBackground = self->palette();

         _HighBackground = self->palette();
         _HighBackground.setColor(QPalette::Highlight, Qt::lightGray);
         _HighBackground.setColor(QPalette::ColorRole::Base, _HighBackground.color(QPalette::Highlight).lighter(40)); //def 210

         _SelectedBackground = self->palette();
         _SelectedBackground.setColor(QPalette::Highlight, Qt::lightGray);
         _SelectedBackground.setColor(QPalette::ColorRole::Base, _SelectedBackground.color(QPalette::Highlight).darker(150));
      });
   }

   QWidgetListItem::~QWidgetListItem()
   {
      auto pos = std::find(_HighlightedItems.begin(), _HighlightedItems.end(), this);
      if (pos != _HighlightedItems.end())
         _HighlightedItems.erase(pos);
   }

   QWidgetListItem* QWidgetListItem::clone() const
   {
      return new QWidgetListItem;
   }

   void QWidgetListItem::enterEvent(QEvent* event)
   {
      QWidget::enterEvent(event);
      HighlightBackground(true);
   }

   void QWidgetListItem::leaveEvent(QEvent* event)
   {
      QWidget::leaveEvent(event);
      HighlightBackground(false);
   }

   void QWidgetListItem::HighlightBackground(bool high)
   {
      if (high)
      {
         if (_HighlightedItems.size() > 0)
         {
            _HighlightedItems.back()->setPalette(_HighlightedItems.back()->_selected ? _SelectedBackground : _DefaultBackground);
            _HighlightedItems.back()->update();
         }

         _HighlightedItems.push_back(this);
         setPalette(_HighBackground);
      }
      else
      {
         setPalette(_selected ? _SelectedBackground : _DefaultBackground);
         auto pos = std::find(_HighlightedItems.begin(), _HighlightedItems.end(), this);
         if (pos != _HighlightedItems.end())
            _HighlightedItems.erase(pos);

         if (_HighlightedItems.size() > 0)
         {
            _HighlightedItems.back()->setPalette(_HighBackground);
            _HighlightedItems.back()->update();
         }
      }
      update();
   }

}
