#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(postMsg()));
    socket->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadOnly);
    socket->waitForConnected();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::postMsg()
{
    QByteArray datagram = socket->readLine();
    datagram.chop(2);

    qDebug() << datagram;

    QString msg(datagram);
    ui->textBrowser->append(msg);
}
