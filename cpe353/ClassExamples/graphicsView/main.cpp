#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>
#include <QtGui>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene myScene(QRect(-100, -100, 400, 300));
    myScene.setBackgroundBrush(QBrush(Qt::lightGray, Qt::SolidPattern));

    QGraphicsSimpleTextItem simpleText("Help Me!");
    simpleText.setPen(QPen(Qt::red));
    simpleText.setPos(0,0);

    QGraphicsTextItem text("I'm Making a Scene!");
    text.setDefaultTextColor(Qt::black);
    text.setPos(100, 100);

    QGraphicsEllipseItem circle(QRect(-50, -50, 100, 100));
    circle.setPen(QPen(Qt::blue));

    myScene.addItem(&simpleText);
    myScene.addItem(&text);
    myScene.addItem(&circle);








    QGraphicsView myView;
    myView.setScene(&myScene);
    myView.show();
    return a.exec();
}
