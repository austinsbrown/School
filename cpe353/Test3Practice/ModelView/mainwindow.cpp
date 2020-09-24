#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listView->setModel(&model);
    ui->tableView->setModel(&model);
    ui->treeView->setModel(&model);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addListItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addListItem()
{
    list.append(ui->lineEdit->text());
    model.setStringList(list);

    ui->lineEdit->clear();
}
