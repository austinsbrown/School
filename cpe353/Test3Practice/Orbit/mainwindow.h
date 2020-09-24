#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>

const int redOrbit = 85;
const int greenOrbit = 100;
const int blueOrbit = 125;

// Planet Diameter
const int sunD = 40;
const int redD = 10;
const int greenD = 20;
const int blueD = 30;

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
    QGraphicsScene *scene;
    QGraphicsItem *red;
    QGraphicsItem *blue;
    QGraphicsItem *green;
    QTimer *timer;
    bool start;

private slots:
    void handleButton();
    void handleTimeout();
    void speed();
};

#endif // MAINWINDOW_H
