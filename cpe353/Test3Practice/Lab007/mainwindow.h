#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draglabel.h"
#include <QGridLayout>

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

    DragLabel   *l1;
    DragLabel   *l3;
    DragLabel   *l2;

    DragLabel   *r1;
    DragLabel   *r3;
    DragLabel   *r2;

    DragLabel   *m1;
    DragLabel   *m3;
    DragLabel   *m2;

    QGridLayout *layout;
};

#endif // MAINWINDOW_H
