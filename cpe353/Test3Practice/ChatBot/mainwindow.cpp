#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVariant>
#include "danddlabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket;
    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
    socket->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadWrite);
    socket->waitForConnected();

    connect(ui->chatEdit, SIGNAL(returnPressed()), this, SLOT(writeSocket()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSocket(){
    QByteArray data = socket->readLine();
    data.chop(2);
    QString msg(data);
    qDebug() << msg;
    ui->chatBrowser->append(msg);
}

void MainWindow::writeSocket(){
    QString msg = ui->chatEdit->text();
    ui->chatEdit->clear();
    ui->chatBrowser->append(msg);
    socket->write(msg.toStdString().c_str(), msg.length());
}
