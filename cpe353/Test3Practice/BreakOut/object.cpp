#include "object.h"
#include "defs.h"
#include <QtDebug>
#include <QList>
#include <QGraphicsScene>

Object::Object()
{
    color = Qt::white;
    x = 0.0;
    y = 0.0;
    w = 0.0;
    h = 0.0;
    dx = 0.00;
    dy = 0.00;
}

QRectF Object::boundingRect() const
{
    qreal adjust = 0.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

QPainterPath Object::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

void Object::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawRect(-w/2, -h/2, w, h);
}

void Object::advance(int step)
{
    if (step == 0)
        return;

    x = this->pos().x();
    y = this->pos().y();

    x = x + dx;
    y = y + dy;

    setPos(x, y);
}

qreal Object::getPosX()
{
    return this->x;
}

qreal Object::getPosY()
{
    return this->y;
}

qreal Object::getWidth()
{
    return this->w;
}

qreal Object::getHeight()
{
    return this->h;
}
