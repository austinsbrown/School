#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRectF>

class Target : public QGraphicsItem
{
public:
    Target();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal dx, dy;
    qreal x, y;
    qreal w, h;

protected:
    void advance(int step);
};

#endif // TARGET_H
