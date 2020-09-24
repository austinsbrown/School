#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "level.h"
#include "lvl1.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* ke);
    void mouseMoveEvent(QMouseEvent* me);

private:
    Ui::MainWindow *ui;
    Level* level;

private slots:
    void loadLevel(int lvl);
};

#endif // MAINWINDOW_H
