#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtDebug>
#include <QHostAddress>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QDialog>
#include <QTcpSocket>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;   // This variable must remain PUBLIC


private slots:
    void updateStatus(QString& s);
    void handleTimeout();
    void changeButton();
    void changeInterval();
    void write();


private:
    QTimer *timer;
        QGraphicsRectItem *sHand;
        QGraphicsRectItem *mHand;
        QGraphicsRectItem *hHand;
        unsigned int seconds;
        unsigned int minutes;
        unsigned int hours;
        QGraphicsScene *scene;
        bool started;
        QTcpSocket *socket;
        QLabel *status;

};

#endif // MAINWINDOW_H
