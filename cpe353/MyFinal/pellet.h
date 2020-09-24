#ifndef PELLET_H
#define PELLET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QDebug>
#include <QGraphicsItem>
#include <QRectF>
#include <QPixmap>
#include <QVector>
#include <QPainter>
#include <defs.h>

class Pellet : public QGraphicsRectItem
{

public:
    Pellet(int, int, int, int, int, int*);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void advance(int);

    int* points;

private:
    qreal x, y, w, h, r;
};
#endif // PELLET_H
