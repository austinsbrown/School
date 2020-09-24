#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <defs.h>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionlvl1, &QAction::triggered, this, [this]{loadLevel(1);});
    connect(ui->actionlvl2, &QAction::triggered, this, [this]{loadLevel(2);});
    connect(ui->actionlvl3, &QAction::triggered, this, [this]{loadLevel(3);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadLevel(int lvl)
{
    qDebug() << "Loading level" << lvl;
    QDialog* d = new QDialog;
    QVBoxLayout* layout = new QVBoxLayout;
    d->setLayout(layout);
    Level* level;
    switch(lvl)
    {
    case 1:
        level = new Level;
        level->loadLevel(lvl1x, lvl1y, 11, 4);
        layout->addWidget(level);
        break;
    case 2:
        level = new Level;
        layout->addWidget(level);
        break;
    case 3:
        level = new Level;
        level->loadLevel(lvl3x, lvl3y, 9, 3);
        layout->addWidget(level);
        break;
    }
    qDebug() << "Loading complete";
    d->exec();
}

void MainWindow::keyPressEvent(QKeyEvent* ke)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent* me)
{

}
