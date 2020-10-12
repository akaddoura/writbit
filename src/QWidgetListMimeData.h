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

#ifndef QT_ADDITIONS_QWIDGET_LIST_MIME_DATA_H
#define QT_ADDITIONS_QWIDGET_LIST_MIME_DATA_H

#include <QtCore/qmimedata.h>
#include <QtCore/qpoint.h>

namespace cw
{
struct QWidgetListItem;
class QWidgetListMimeData : public QMimeData
{
public:

    //static constexpr char MimeType[] = "application/x-qwidget-list-item";

    QWidgetListItem* Widget = nullptr;
    QPoint HotSpot;

    Q_OBJECT;
};
}
#endif // QWIDGETLISTMIMEDATA_H
