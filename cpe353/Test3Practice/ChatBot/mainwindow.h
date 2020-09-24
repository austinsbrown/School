#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "danddlabel.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDialog>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void readSocket();
    void writeSocket();


private:
    QTcpSocket* socket;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
