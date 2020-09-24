#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel("0", this);
    statusBar()->addWidget(status);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::poplulateComboBar);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::poplulateComboBar()
{
    QStringList list;
    QString fileName = ui->lineEdit->text();
    QFile someFile(ui->lineEdit->text());

    if(!someFile.exists())
    {
        qDebug() << "File not found";
    }

    else if(!someFile.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Unable to open file";
    }

    else
    {
        qDebug() << "File opened";
        QTextStream someStream(&someFile);
        QString someValue;
        while(!someStream.atEnd())
        {
            someValue = someStream.readLine();
            list.append(someValue);
            qDebug() << someValue;
        }
        ui->comboBox->addItems(list);
    }
}



void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    if(ke && ke->key() == Qt::Key_Escape)
    {
        int count = status->text().toInt();
        count++;
        status->setNum(count);
    }
    QMainWindow::keyPressEvent(ke);
}














