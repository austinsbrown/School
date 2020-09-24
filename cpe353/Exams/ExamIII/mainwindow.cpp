#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /******* Populate grid layout with custom Label objects *******/
    for(int r = 0; r < 2; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            Label* pmLabel = new Label(this);
            pmLabel->setFrameStyle(QFrame::WinPanel);
            QPixmap* pm = new QPixmap(60,60);
            if (r%2 == 0) pm->fill(Qt::blue); else pm->fill(Qt::white);
            pmLabel->setPixmap(*pm);
            ui->gridLayout->addWidget(pmLabel, r, c);
            connect(pmLabel, SIGNAL(sendStatus(QString &)), this, SLOT(updateStatus(QString&)));
        }
    }
    /*********** Do not modify or delete the above code **********/



    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(scene);

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

    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(changeInterval()));
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    connect(ui->button, SIGNAL(clicked(bool)), this, SLOT(changeButton()));
    started = false;

    socket = new QTcpSocket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(write()));
    socket->connectToHost(QHostAddress::LocalHost, 5678);
    socket->waitForConnected();

    QPixmap *r = new QPixmap(300, 150);
    r->fill(Qt::red);
    ui->imageLabel->setPixmap(r->scaled(300, 150));

    status = new QLabel;
    ui->statusBar->addWidget(status);
    status->setFrameStyle(QFrame::Panel);
    status->setText("Ready");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus(QString& s)
{

}


void MainWindow::handleTimeout()
{
    static int srotation = 0;
    static float mrotation = 0;
    static float hrotation = 0;

    sHand->setRotation(srotation += 6);
    mHand->setRotation(mrotation+=0.1);
    hHand->setRotation(hrotation+=0.0083333);



}


void MainWindow::changeInterval()
{
    int value = ui->slider->value();
    int newtime = 1000 / value;
    timer->setInterval(newtime);
}


void MainWindow::changeButton()
{
    if(started == false)
    {
        started = true;
        ui->button->setText("Stop");
        timer->start();
    }
     else if (started == true)
    {
        started = false;
        ui->button->setText("Start");
        timer->stop();
    }
}


void MainWindow::write()
{
    QPixmap pixmap;
    QByteArray array = socket->readAll();
    QString string(array);

    QPixmap* pm = new QPixmap(300, 150);
    pm->fill(Qt::blue);
    ui->imageLabel->setPixmap(*pm);

    if(string == array)
    {
        QPixmap* pm = new QPixmap(300, 150);
        pm->fill(Qt::blue);
        ui->imageLabel->setPixmap(*pm);

        QPainter p(pm);
        p.setPen(Qt::white);
        p.setFont(QFont("Arial", 18));

        QPoint tp(40,40);
        p.drawText(tp, array);
        ui->imageLabel->setPixmap(pm->scaled(300, 150));
    }

}























