#include "enemy.h"

Enemy::Enemy(qreal x, qreal y, qreal _dx, qreal _dy)
{
    //set move directions
    dx = _dx;
    dy = _dy;

    QSqlQuery query;

    if(!query.exec( "SELECT * FROM enemy_images" ))
    {
        qDebug() << "Error getting targets from table: " << query.lastError();
    }
    else
    {
        int i = 0;
        while(query.next())
        {
            QByteArray outByteArray = query.value(1).toByteArray();
            enemyPix.loadFromData(outByteArray, "PNG");
            i++;
        }
    }

    //scale them
    for(int i = 0; i < 10; i++)
    {
        enemyPix = enemyPix.scaled(80, 80, Qt::KeepAspectRatio);
    }

    //set pixmap
    this->setPixmap(enemyPix);

    //set rand position
    this->setPos(x+(XMAX/2), y+(YMAX/2));

    //set rotation origin
    this->setTransformOriginPoint(40, 40);

    //timer to make move in 1 direction
    QTimer * t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    t->start(12);
}

void Enemy::move()
{
    //if hit stop and rotate
    if(isHit)
    {
        this->setRotation(this->rotation() + 99);
    }
    //else perform movement
    else
    {
        //delete if hit
        QList<QGraphicsItem *> colliding_items = collidingItems();

        for(int i = 0; i < colliding_items.size(); i++)
        {
            if(typeid(*(colliding_items[i])) == typeid(Bullet))
            {
                scene()->removeItem(colliding_items[i]);

                delete colliding_items[i];
                stop();
                return;
            }
        }

        //bounce off right wall
        if(this->pos().x() > XMAX - 100)
        {
            dx = dx * -1;

            this->setPos(x()+dx, y() + dy);
        }
        //bounce off left wall
        else if(this->pos().x() < 0.0)
        {
            dx = dx * -1;

            this->setPos(x() + dx, y() + dy);
        }
        //bounce off top wall
        else if(this->pos().y() < 0)
        {
            dy = dy * -1;

            this->setPos(x()+dx, y() + dy);
        }
        //bounce off bottom wall
        else if(this->pos().y() > YMAX - 80)
        {
            dy = dy * -1;

            this->setPos(x()+dx, y() + dy);
        }
        else
        {
            this->setPos(x()+dx, y() + dy);

            //iterate through pic animations
            static int i = 0;
            this->setPixmap(enemyPix);
            i++;

            if(i == 10)
            {
                i = 0;
            }
        }
    }
}

//when hit
void Enemy::stop()
{
    isHit = true;
    dy = 0;
    dx = 0;
}

