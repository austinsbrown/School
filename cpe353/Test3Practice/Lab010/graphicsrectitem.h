#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H
#include "defs.h"
#include <QGraphicsRectItem>

class GraphicsRectItem : public QGraphicsRectItem
{
public:
    GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = 0);

protected:
    void advance(int phase);

private:
    qreal dy;
};

#endif // GRAPHICSRECTITEM_H
