#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QMouseEvent>
#include <QRegularExpressionValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *e);

private:
    Ui::MainWindow *ui;
    QLabel *status;
    QRegularExpressionValidator *validator;
    bool event(QEvent *e);

private slots:
    void spawn();
    void closeAll();
    void load();
    void print();
};

#endif // MAINWINDOW_H
