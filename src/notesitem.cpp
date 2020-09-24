#include "notesitem.h"
#include <QDebug>
#include <QPainter>

using namespace cw;

struct Grabber: QWidget
{
    void paintEvent(QPaintEvent* event) override
    {
        QPen pen(QColor(180,180,180,128));
        pen.setWidth(3);

        const int h = height();
        const int w = width();

        QPainter painter(this);
        painter.setPen(pen);
        static constexpr int offset = 4;
        static constexpr int diagonal = 10;
        for (int y = offset; y < h - (offset + diagonal); y += diagnal)
        {
            painter.drawLine(0, y, w, y+diagonal);
        }
    }
};

