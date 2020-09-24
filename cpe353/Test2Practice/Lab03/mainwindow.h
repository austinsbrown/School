#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QRegularExpressionValidator>
#include <QIcon>
#include <QMenu>
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

private:
    Ui::MainWindow *ui;

    QAction*      action1;
    QAction*      action2;
    QAction*      action3;
    QMenu*        actionMenu;
    QLabel*       status;

public slots:
    void defaultAreaCode();
    void defaultPrefix();
    void defaultSubscriber();
    void setStatus();
};

#endif // MAINWINDOW_H
