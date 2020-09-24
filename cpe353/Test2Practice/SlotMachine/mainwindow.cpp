#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::processSpin);

    quitAction = new  QAction("Quit", this);

    ui->mainToolBar->addAction(quitAction);

    connect(quitAction, &QAction::triggered,
            this, &MainWindow::close);

    statusLabel = new QLabel("Ready");
    statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::processSpin()
{
    int one = qrand() % MODULUS;
    int two = qrand() % MODULUS;
    int three = qrand() % MODULUS;

    ui->label_6->setText(QString::number(one));
    ui->label_7->setText(QString::number(two));
    ui->label_8->setText(QString::number(three));

    if(one == two && two == three)
    {
        statusLabel->setText("Winner!");
        int spins = ui->spinLabel->text().toInt() + 1;
        int wins = ui->winLabel->text().toInt() + 1;
        ui->spinLabel->setText(QString::number(spins));
        ui->winLabel->setText(QString::number(wins));

    }

    else
    {
        statusLabel->setText("Loser!");
        int spins = ui->spinLabel->text().toInt() + 1;
        ui->spinLabel->setText(QString::number(spins));
    }

}
