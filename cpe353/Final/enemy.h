#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTimer>

#include "defs.h"
#include "bullet.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(qreal x, qreal y, qreal _dx, qreal _dy);

private slots:
    void move();

private:
    void stop();
    bool isHit = false;
    QPixmap enemyPix;
    qreal dx, dy;
};

#endif // ENEMY_H
