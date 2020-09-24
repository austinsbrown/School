#include "draglabel.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QImage>
#include <QDrag>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QDropEvent>

DragLabel::DragLabel(const QString & path, QWidget * parent) : QLabel(parent)
{
    this->setFixedSize(50, 50);
    filename = path;
    setPixmap(QPixmap(filename));
    this->setAcceptDrops(true);
}


void DragLabel::mousePressEvent(QMouseEvent *event)
{
    if(event && event->button() == Qt::LeftButton)
    {
        QMimeData *md = new QMimeData;
        md->setImageData(*this->pixmap());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(md);

        if(pixmap())
        {
            drag->start();
        }
    }
}

void DragLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event && event->mimeData())
    {
        const QMimeData * md = event->mimeData();

        if(md->hasImage())
        {
            event->acceptProposedAction();
        }
    }
    QLabel::dragEnterEvent(event);
}

void DragLabel::dropEvent(QDropEvent *event)
{
    QPixmap pic;
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage())
        {
            pic = md->imageData().value<QPixmap>();
        }
    }
    if(!pic.isNull())
    {
        setPixmap(pic);
    }
    QLabel::dropEvent(event);
}
