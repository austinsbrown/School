#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QGraphicsScene *scene;
    QTimer *timer;
    QGraphicsRectItem *sHand;
    QGraphicsRectItem *mHand;
    QGraphicsRectItem *hHand;
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;

private slots:
    void download();
    void spawn();
    void handleTimeout();
    void changeInterval();
};

#endif // MAINWINDOW_H
