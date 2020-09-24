#include "danddlabel.h"
#include <QDrag>
#include <QMimeData>

DAndDLabel::DAndDLabel(QString s)
{
    setAcceptDrops(true);
    setText(s);
}


void DAndDLabel::mousePressEvent(QMouseEvent *event)
{
    if(event && event->button() == Qt::LeftButton)
    {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData();

        mimeData->setText(text());
        drag->setMimeData(mimeData);

        drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
    }

    else
        return;

    QLabel::mousePressEvent(event);
}


void DAndDLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event && event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}


void DAndDLabel::dropEvent(QDropEvent *event)
{
    setText(event->mimeData()->text());
    event->acceptProposedAction();
}


