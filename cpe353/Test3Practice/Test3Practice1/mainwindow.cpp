#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "danddlabel.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadOnly);
    socket->waitForConnected();

    connect(ui->goButton, &QPushButton::clicked, this, &MainWindow::spawn);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::black);

    QPen *pen = new QPen;
    pen->setColor(Qt::blue);
    pen->setWidth(1);

    QGraphicsEllipseItem *clock = scene->addEllipse(-100, -100, 200, 200, *pen);

    pen->setWidth(5);
    for(int i = 0; i < 12; i++)
    {
        QGraphicsLineItem *lines = scene->addLine(0, -100, 0, -85, *pen);
        lines->setRotation(30 * i);
    }

    pen->setColor(Qt::red);
    pen->setWidth(6);
    sHand = scene->addRect(0, -90, 0, 80, *pen);

    pen->setColor(Qt::green);
    mHand = scene->addRect(0, -100, 0, 90, *pen);

    pen->setColor(Qt::white);
    hHand = scene->addRect(0, -60, 0, 60, *pen);



    timer = new QTimer(this);
    timer->setInterval(1000);

    seconds = 0;
    minutes = 0;
    hours = 0;

    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    connect(ui->button, SIGNAL(clicked(bool)), timer, SLOT(start()));
    //connect(socket, SIGNAL(readyRead()), this, SLOT(handleRXImage()));
    //connect(ui->goButton, SIGNAL(clicked(bool)), this, SLOT(goButtonClicked()));
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(changeInterval()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::download()
{
    QByteArray datagram = socket->readAll();
    ui->bytesLabel->setText(QString::number(datagram.size()));
    QPixmap *p = new QPixmap;
    p->loadFromData(datagram, "JPG");
    p->scaled(240, 180);
    ui->imageLabel->setPixmap(*p);
}


void MainWindow::spawn()
{
    QString l = ui->leftEdit->text();
    QString r = ui->rightEdit->text();
    ui->leftEdit->clear();
    ui->rightEdit->clear();

    DandDLabel *left = new DandDLabel(l);
    DandDLabel *right = new DandDLabel(r);

    left->show();
    right->show();
}


void MainWindow::handleTimeout()
{
    seconds++;
    static int srotation = 0;
    static float mrotation = 0;
    static float hrotation = 0;

    if(srotation == 59)
        srotation = 0;
    else
        sHand->setRotation(srotation += 6);

    if(seconds == 59 && minutes < 60)
    {
        seconds = 0;
        minutes++;
        if(mrotation != 0 && (mrotation - 360) == 0)
            mrotation = 0;
        else
            mHand->setRotation(mrotation+=0.1);
    }

    if(minutes >= 60)
    {
        minutes = 0;
        hours++;
        if(hrotation != 0 && (hrotation - 360) == 0)
            hrotation = 0;
        else
            hHand->setRotation(hrotation+=0.0083333);
    }

    qDebug() << seconds << " : " << minutes << " : " << hours;
}


void MainWindow::changeInterval()
{
    int value = ui->slider->value();
    int newtime = 1000 / value;
    timer->setInterval(newtime);
    timer->start();
}

