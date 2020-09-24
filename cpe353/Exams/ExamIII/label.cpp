#include "label.h"

Label::Label(QWidget * parent) : QLabel(parent)
{
    this->setFixedSize(50, 50);

    setPixmap(QPixmap(filename));
    this->setAcceptDrops(true);
}


void Label::mousePressEvent(QMouseEvent *event)
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


void Label::dragEnterEvent(QDragEnterEvent *event)
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

void Label::dropEvent(QDropEvent *event)
{
    QPixmap pic;
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage())
        {
            pic = md->imageData().value<QPixmap>();
        }
        else if(md->hasText())                          // read image path name
        {

            QString file = md->text();                  // get path name
            file.remove(6);                             // get rid of start characters
            file.chop(2);                               // GET RID OF END CHARACTERS
            QFile imageFile(file);

            if(!imageFile.exists())                     // load the image
            {
                return;
            }
                else if (!imageFile.open(QIODevice::ReadOnly))
                {
                    qDebug() << "File is read only";
                }
                else
                {
                    qDebug() << "File opened";
                }

                QByteArray ba = imageFile.readAll();


                pic.loadFromData(ba);


        }
    }
    if(!pic.isNull())
    {
        setPixmap(pic);
    }
    QLabel::dropEvent(event);
}
