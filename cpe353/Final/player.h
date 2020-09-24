#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSqlQuery>
#include <QByteArray>
#include <QSqlError>
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>

#include "enemy.h"
#include "defs.h"
#include "bullet.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

protected:
    void keyPressEvent(QKeyEvent * event);

private slots:
    void move();

private:
    void endGame();
    QPixmap playerPixmap[16];
    int dx = 0, dy = 0;
    direction current_dir = stop;
};

#endif // PLAYER_H
