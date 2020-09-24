#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(Qt::black);

    ui->graphicsView->setScene(scene);

    QPen *pen = new QPen;
    QBrush *brush = new QBrush;

    pen->setColor(Qt::white);
    scene->addEllipse(-100, -100, 200, 200, *pen);

    pen->setColor(Qt::yellow);
    brush->setColor(Qt::yellow);
    brush->setStyle(Qt::SolidPattern);
    scene->addEllipse(-sunD/2, -sunD/2, sunD, sunD, *pen, *brush);

    pen->setColor(Qt::red);
    brush->setColor(Qt::red);
    brush->setStyle(Qt::SolidPattern);
    red = scene->addEllipse(-redD/2, redOrbit, redD, redD, *pen, *brush);

    pen->setColor(Qt::green);
    brush->setColor(Qt::green);
    brush->setStyle(Qt::SolidPattern);
    green = scene->addEllipse(-greenD/2, greenOrbit, greenD, greenD, *pen, *brush);

    pen->setColor(Qt::blue);
    brush->setColor(Qt::blue);
    brush->setStyle(Qt::SolidPattern);
    blue = scene->addEllipse(-blueD/2, blueOrbit, blueD, blueD, *pen, *brush);

    timer = new QTimer(this);
    timer->setInterval(16.667);

    connect(ui->button, &QPushButton::clicked, this, &MainWindow::handleButton);
    start = false;
    connect(timer, &QTimer::timeout, this, &MainWindow::handleTimeout);
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(speed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleButton()
{
    if(start == false)
    {
        start = true;
        ui->button->setText("Stop");
        timer->start();
    }
    else if (start == true)
    {
        start = false;
        ui->button->setText("Start");
        timer->stop();
    }
}


void MainWindow::handleTimeout()
{
    red->setRotation(red->rotation() + 6);
    blue->setRotation(blue->rotation() + .008333);
    green->setRotation(green->rotation() + .1);
    scene->update();
}


void MainWindow::speed()
{
    int s = ui->slider->value();
    timer->setInterval(16.667 / s);
    timer->start();
}












