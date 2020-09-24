#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QTimer>

#include <QDebug>

#include "defs.h"

class Bullet : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Bullet(direct dir, QPointF pos);

private slots:
    void move();

private:
    direct dir;
};

#endif // BULLET_H
