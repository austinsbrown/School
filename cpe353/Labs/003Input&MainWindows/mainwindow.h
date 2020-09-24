#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QLabel>
#include <QToolBar>
#include <QMenu>

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

    QAction                     *action1;
    QAction                     *action2;
    QAction                     *action3;
    QRegularExpressionValidator *areaCode;
    QRegularExpressionValidator *customerVal;
    QLabel                      *status;
    QToolBar                    *toolBar;
    QMenu                       *menu;

private slots:
    void dArea();
    void dSub();
    void dCust();
    void clear();
    void dial();
};

#endif // MAINWINDOW_H
