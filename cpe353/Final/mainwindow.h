#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>

#include <QGraphicsScene>
#include <QGraphicsLineItem>

#include "defs.h"
#include "player.h"
#include "enemy.h"

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
    QGraphicsScene * scene;
    QSqlDatabase db;
    qreal dx[10];
    qreal dy[10];

    qreal x[10];
    qreal y[10];

    bool ok = true;
};

#endif // MAINWINDOW_H
