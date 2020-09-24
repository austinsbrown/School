#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    socket = new QUdpSocket;
    connect(socket, &QUdpSocket::readyRead, this, &Dialog::postMsg);
    socket->bind(QHostAddress::LocalHost, 5678);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::postMsg()
{
    QByteArray datagram;

    while (socket->hasPendingDatagrams())
    {
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());

        QString msg;
        QTextStream in(&datagram);

        msg = in.readAll();
        msg = msg.trimmed();
        ui->textBrowser->append(msg);
    }
}
