#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QRegularExpressionValidator>
#include <QKeyEvent>
#include <QMouseEvent>

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

    QRegularExpressionValidator *valid;
    QMenu *options;
    QAction *NonModal;
    QLabel *stat;

private slots:
    void fileLoad();
    void nonModal();
    void setDial();
    void setSpin();

protected:
    void mousePressEvent(QMouseEvent *);

};

#endif // MAINWINDOW_H
