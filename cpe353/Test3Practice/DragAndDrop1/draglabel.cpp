#include "draglabel.h"
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QImage>
#include <QPixmap>

DragLabel::DragLabel(const QString& path, QWidget* parent) : QLabel (parent)
{
    fileName = path;

    this->setFixedSize(50, 50);
    setPixmap(QPixmap(fileName));
}


void DragLabel::mousePressevent(QMouseEvent *event)
{
    if(event && event->button() == Qt::LeftButton)
    {
        QMimeData *md = new QMimeData;
        QImage pic(fileName);
        md->setImageData(pic);

        QDrag* drag = new QDrag(this);
        drag->setMimeData(md);

        if(pixmap())
        {
            QSize s = this->sizeHint();
            drag->setPixmap(pixmap()->scaled(s));
        }
        drag->start();
    }
}
