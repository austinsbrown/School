#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    action1 = new QAction(QIcon(":/icons/icons8-bill-cipher-50.png"), "Area Code", this);
    action2 = new QAction(QIcon(":/icons/icons8-iron-man-50.png"), "Prefix", this);
    action3 = new QAction(QIcon(":/icons/icons8-empire-50.png"), "Subscriber", this);

    ui->mainToolBar->addAction(action1);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(action2);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(action3);

    status = new QLabel("Ready");
    statusBar()->addWidget(status);

    menu = menuBar()->addMenu("&Actions");
    menu->addAction(action1);
    ui->mainToolBar->addSeparator();
    menu->addAction(action2);
    ui->mainToolBar->addSeparator();
    menu->addAction(action3);

    connect(action1, &QAction::triggered, this, &MainWindow::dArea);
    connect(action2, &QAction::triggered, this, &MainWindow::dSub);
    connect(action3, &QAction::triggered, this, &MainWindow::dCust);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->dialButton, &QPushButton::clicked, this, &MainWindow::dial);


    QRegularExpression area = QRegularExpression("[0-9]{3}");
    areaCode = new QRegularExpressionValidator(area, this);
    ui->areaCodeEdit->setValidator(areaCode);
    ui->subEdit->setValidator(areaCode);

    QRegularExpression c = QRegularExpression("[0-9]{4}");
    customerVal = new QRegularExpressionValidator(c, this);
    ui->customerEdit->setValidator(customerVal);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::dArea()
{
    ui->areaCodeEdit->setText("999");
}


void MainWindow::dSub()
{
    ui->subEdit->setText("999");
}

void MainWindow::dCust()
{
    ui->customerEdit->setText("9999");
}


void MainWindow::clear()
{
    ui->areaCodeEdit->clear();
    ui->customerEdit->clear();
    ui->subEdit->clear();
}


void MainWindow::dial()
{
    QString area = ui->areaCodeEdit->text();
    QString sub = ui->subEdit->text();
    QString cust = ui->customerEdit->text();

    QString number = area + "-" + sub + + "-" + cust;
    status->setText(number);
}
