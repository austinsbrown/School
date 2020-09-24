#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap mymap(400, 300);

    QPainter p(&mymap);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap));
    p.drawRect(10, 10, 380, 280);

    p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::SquareCap));
    QRect rect1(25, 25, 50, 30);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::blue, 2, Qt::DashLine, Qt::SquareCap));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 2, Qt::DotLine, Qt::RoundCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 2, Qt::DashDotLine, Qt::FlatCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::SquareCap));
    p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap));
    p.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::green, Qt::VerPattern));
    rect1.translate(100, 0);
    p.drawRect(rect1);


    QLabel myLable;
    myLable.setPixmap(mymap);
    myLable.show();

    return a.exec();
}
