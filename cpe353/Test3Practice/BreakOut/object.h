#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRect>

class Object : public QGraphicsItem
{
public:
    explicit Object();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal getPosX();
    qreal getPosY();
    qreal getWidth();
    qreal getHeight();

protected:
    void advance(int step);
    QColor color;
    qreal x, y;
    qreal w, h;
    qreal dx, dy;
};

#endif // OBJECT_H
