#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadImage = new QAction("Load Image", this);
    connect(loadImage, &QAction::triggered, this, &MainWindow::load);
    loadImage->setShortcuts(QKeySequence::Open);

    menu = menuBar()->addMenu("File");
    menu->addAction(loadImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::load()
{
    qDebug() << "Loading Image Now";

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Images (*.png *.jpg)"));
    QFile imageFile(filename);

    if(!imageFile.exists())
    {
        qDebug() << "File does not exist.";
        return;
    }
    else if (!imageFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "File is read only";
    }
    else
    {
        qDebug() << "File opened";
    }

    QByteArray ba = imageFile.readAll();
    QPixmap pm;
    pm.loadFromData(ba);
    ui->label_2->setPixmap(pm);
}


