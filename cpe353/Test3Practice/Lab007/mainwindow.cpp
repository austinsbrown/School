#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l1 = new DragLabel(":/icons/icons8-bill-cipher-50.png", this);
    l2 = new DragLabel(":/icons/icons8-bill-cipher-50.png", this);
    l3 = new DragLabel(":/icons/icons8-bill-cipher-50.png", this);

    m1 = new DragLabel(":/icons/icons8-empire-50.png", this);
    m2 = new DragLabel(":/icons/icons8-empire-50.png", this);
    m3 = new DragLabel(":/icons/icons8-empire-50.png", this);

    r1 = new DragLabel(":/icons/icons8-iron-man-50.png", this);
    r2 = new DragLabel(":/icons/icons8-iron-man-50.png", this);
    r3 = new DragLabel(":/icons/icons8-iron-man-50.png", this);

    ui->gridLayout->addWidget(l1, 0, 0);
    ui->gridLayout->addWidget(l2, 1, 0);
    ui->gridLayout->addWidget(l3, 2, 0);

    ui->gridLayout->addWidget(m1, 0, 1);
    ui->gridLayout->addWidget(m2, 1, 1);
    ui->gridLayout->addWidget(m3, 2, 1);

    ui->gridLayout->addWidget(r1, 0, 2);
    ui->gridLayout->addWidget(r2, 1, 2);
    ui->gridLayout->addWidget(r3, 2, 2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
