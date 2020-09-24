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
