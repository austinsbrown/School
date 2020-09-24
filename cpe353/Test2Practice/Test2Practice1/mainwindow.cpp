#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status = new QLabel(this);
    status->setNum(0);
    ui->statusBar->addWidget(status);

    QRegularExpression s("[0-9]{1}[0-9]{1}");
    validator = new QRegularExpressionValidator(s, this);
    ui->lineEdit->setValidator(validator);

    connect(ui->closeAllButton, &QPushButton::clicked, this, &MainWindow::closeAll);
    connect(ui->spawnButton, &QPushButton::clicked, this, &MainWindow::spawn);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::load);

    ui->filteredEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *e)
{
    if(!e) return  QMainWindow::event(e);

    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ke = static_cast<QMouseEvent*>(e);
        if(ke->buttons() == Qt::RightButton)
        {
            int i =status->text().toInt();
            i++;
            status->setNum(i);
            qDebug() << QCursor::pos();
        }
    }
    return  QMainWindow::event(e);
}


void MainWindow::spawn()
{
    int num = ui->lineEdit->text().toInt();
    for(int i=0; i<num; i++)
    {
        QDialog *x = new QDialog;
        QLabel *y = new QLabel;
        QVBoxLayout *l = new QVBoxLayout;
        QString s = "Dialog # " + QString::number(i+1);
        x->setLayout(l);
        y->setText(s);
        l->addWidget(y);
        connect(ui->closeAllButton, &QPushButton::clicked, x, &QDialog::accept);
        x->show();
    }
}


void MainWindow::closeAll()
{
    ui->lineEdit->clear();
}


void MainWindow::load()
{
    int actionNum = 0;
    QStringList list;
    QString fileName = ui->fileNameEdit->text();
    QFile someFile(ui->fileNameEdit->text());
    ui->fileNameEdit->clear();

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
            status->setText(fileName);
            QTextStream someStream(&someFile);
            QString someValue;
            disconnect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::load);
            while(!someStream.atEnd())
            {
                someValue = someStream.readLine();
                list.append(someValue);
                qDebug() << someValue;
                actionNum++;
            }
        }
        for (int i=0; i < actionNum; i++)
        {
            QAction *x = new QAction(list[i]);
            ui->mainToolBar->addAction(x);
            connect(x, &QAction::triggered, this, &MainWindow::print);
        }

}


void MainWindow::print()
{
    qDebug() << "Triggered";
}


bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{
    if(!watched || !e) return QWidget::eventFilter(watched, e);

        if(watched == ui->filteredEdit && e->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(e);
            if(ke->key() == Qt::Key_PageUp)
            {
                status->setText("Up");
            }
            else if(ke->key() == Qt::Key_PageDown)
            {
                status->setText("Down");
            }
        }
        return QWidget::eventFilter(watched, e);
}















