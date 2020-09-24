#ifndef DRAGLABEL_H
#define DRAGLABEL_H

#include <QLabel>

class DragLabel : public QLabel
{
public:
    DragLabel(const QString & path, QWidget* parent = 0);

protected:
    void mousePressEvent(QMouseEvent * event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);

private:
    QString filename;
};

#endif // DRAGLABEL_H
