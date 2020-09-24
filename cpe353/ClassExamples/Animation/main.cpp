#include <QApplication>
#include <QtGui>
#include <QGraphicsItemAnimation>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap mySpaceShip(100, 100);
    mySpaceShip.fill(Qt::black);
    QPainter p(&mySpaceShip);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setWindow(-50, -50, 100, 100);

    p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::SolidPattern));

    QPoint points[4] = {QPoint(0, 25), QPoint(15, -25),
                        QPoint(0, 0), QPoint(-15, -25)};

    p.drawPolygon(points, 4);

    QGraphicsPixmapItem spaceship(mySpaceShip);

    QTimeLine *timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(&spaceship);
    animation->setTimeLine(timer);

    for (int i=0; i<200; ++i)
    {
        animation->setPosAt(i/200.0, QPointF(i,i));
    }





















    return a.exec();
}
