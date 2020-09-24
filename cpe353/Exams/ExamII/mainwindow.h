#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QFile>
#include <QtDebug>
#include <QMouseEvent>
#include <QIntValidator>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QKeyEvent>

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
    int lineCount;
    QLabel *status;
    QRegularExpressionValidator *valid;
    QAction *save2;
    QAction *load2;
    QMenu *actionMenu;

private slots:
    void protect();
    void load();
    void save();
    void spawn();

};

#endif // MAINWINDOW_H
