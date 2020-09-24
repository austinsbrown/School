#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QToolBar>

namespace Ui {
class MainWindow;
}

const int MODULUS = 7;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QAction*        quitAction;

    QMenu*          optionsMenu;
    QToolBar*       toolBar;
    QLabel*         statusLabel;

private slots:
    void processSpin();

signals:
    void updateString();
};

#endif // MAINWINDOW_H
