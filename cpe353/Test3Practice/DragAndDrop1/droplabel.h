#ifndef DROPLABEL_H
#define DROPLABEL_H
#include <QLabel>
#include <QtGui>
#include <QString>
#include <QWidget>
#include <QLabel>

class DropLabel : public QLabel
{
    Q_OBJECT

public:
    DropLabel();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DROPLABEL_H
