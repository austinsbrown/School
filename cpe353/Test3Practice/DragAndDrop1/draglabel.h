#ifndef DRAGLABEL_H
#define DRAGLABEL_H
#include <QLabel>
#include <QString>
#include <QMouseEvent>

class DragLabel : public QLabel
{
    Q_OBJECT
public:
    DragLabel(const QString& path, QWidget* parent = 0);

protected:
    void mousePressevent(QMouseEvent *event);

private:
    QString fileName;
};

#endif // DRAGLABEL_H
