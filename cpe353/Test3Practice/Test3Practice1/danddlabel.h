#ifndef DANDDLABEL_H
#define DANDDLABEL_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

class DandDLabel : public QLabel
{
public:
    DandDLabel(QString s);

private:
    void mousePressEvent(QMouseEvent *event);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // DANDDLABEL_H
