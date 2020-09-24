#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QTimer>
#include <QLabel>
#include <QBrush>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QVector>
#include "cat.h"
#include "pellet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool notMoving = true;

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QGraphicsScene *scene;
    QGraphicsRectItem* walls;
    Cat* cat;
    QPixmap* pix;
    QVector<QPixmap*> catpixs;
    Pellet* temp_pellet;
    QVector<Pellet*> pellets;
    QTimer *timer;
    int points;

protected:
    void keyPressEvent(QKeyEvent *);

};

#endif // MAINWINDOW_H
