#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(Qt::blue);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    p1 = new Projectile;
    p1->setPos(-200, -150);
    scene->addItem(p1);

    t1 = new Target;
    t1->setPos(-200, 100);
    scene->addItem(t1);

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->setInterval(1000/33);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
