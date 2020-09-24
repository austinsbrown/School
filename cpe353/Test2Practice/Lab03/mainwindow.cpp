#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->clearButton, &QPushButton::clicked, ui->areaCode, &QLineEdit::clear);
    connect(ui->clearButton, &QPushButton::clicked, ui->prefix, &QLineEdit::clear);
    connect(ui->clearButton, &QPushButton::clicked, ui->subscriber, &QLineEdit::clear);

    QRegularExpressionValidator* three = new QRegularExpressionValidator(QRegularExpression("[0-9]{3}"), ui->areaCode);
    QRegularExpressionValidator* four = new QRegularExpressionValidator(QRegularExpression("[0-9]{4}"), ui->subscriber);
    ui->areaCode->setValidator(three);
    ui->prefix->setValidator(three);
    ui->subscriber->setValidator(four);

    QRegularExpression r("[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}");
    QRegularExpressionValidator* capLow = new QRegularExpressionValidator(r, ui->lineEdit_4);
    ui->lineEdit_4->setValidator(capLow);

    action1 = new QAction("Default Area Code", this);
    action2 = new QAction("Default Prefix", this);
    action3 = new QAction("Default Subscriber", this);

    actionMenu = menuBar()->addMenu("&Actions");

    actionMenu->addAction(action1);
    actionMenu->addSeparator();
    actionMenu->addAction(action2);
    actionMenu->addSeparator();
    actionMenu->addAction(action3);
    actionMenu->addSeparator();

    ui->mainToolBar->addAction(action1);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(action2);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(action3);
    ui->mainToolBar->addSeparator();

    connect(action1, &QAction::triggered, this, &MainWindow::defaultAreaCode);
    connect(action2, &QAction::triggered, this, &MainWindow::defaultPrefix);
    connect(action3, &QAction::triggered, this, &MainWindow::defaultSubscriber);

    status = new QLabel("Ready");
    ui->statusBar->addWidget(status);

    connect(ui->dialButton, &QPushButton::clicked, this, &MainWindow::setStatus);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::defaultAreaCode()
{
    ui->areaCode->setText("999");
}



void MainWindow::defaultPrefix()
{
    ui->prefix->setText("999");
}



void MainWindow::defaultSubscriber()
{
    ui->subscriber->setText("9999");
}


void MainWindow::setStatus()
{
    QString s = ui->areaCode->text() + "-" + ui->prefix->text() + "-" + ui->subscriber->text();
    status->setText(s);
}
