#include "bullet.h"

Bullet::Bullet(direction curr_dir, QPointF pos) : QGraphicsEllipseItem(pos.x() + 10, pos.y() + 10, 10, 10)
{
    //set enum of current direction
    dir = curr_dir;

    //set brush color
    this->setBrush(QBrush(Qt::yellow));

    //timer to make move in 1 direction
    QTimer * t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    t->start(16);
}

//movement
void Bullet::move()
{
    if(dir == up)
    {
        if(this->pos().y() > 0)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x(), y() - 6);
        }
    }
    else if (dir == l)
    {
        if(this->pos().x() > 0)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x() - 6, y());
        }
    }
    else if(dir == down)
    {
        if(this->pos().y() > YMAX)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x(), y()+6);
        }
    }
    else if(dir == r)
    {
        if(this->pos().x() > XMAX)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x()+6, y());
        }
    }
}
