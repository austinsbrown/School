#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(1000);
    paused = true;

    ui->secondLabel->setText(QString::number(clock.secs()));
    ui->minuteLabel->setText(QString::number(clock.mins()));
    ui->hourLabel->setText(QString::number(clock.hrs()));

    connect(ui->quit, &QPushButton::clicked, this, &Dialog::close);
    connect(ui->start, &QPushButton::clicked, this, &Dialog::startTimer);
    connect(ui->pause, &QPushButton::clicked, this, &Dialog::pauseTimer);
    connect(ui->clear, &QPushButton::clicked, this, &Dialog::clearTimer);
    connect(timer, &QTimer::timeout, this, &Dialog::updateDisplay);


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::startTimer()
{
    timer->start();
    paused = false;
}


void Dialog::pauseTimer()
{
    timer->stop();
    paused = true;
}


void Dialog::clearTimer()
{
    timer->stop();
    paused = true;
    clock.reset();

    ui->secondLabel->setText(QString::number(clock.secs()));
    ui->minuteLabel->setText(QString::number(clock.mins()));
    ui->hourLabel->setText(QString::number(clock.hrs()));
}


void Dialog::updateDisplay()
{
    if(!paused)
    {
        clock.addSecond();

        ui->secondLabel->setText(QString::number(clock.secs()));
        ui->minuteLabel->setText(QString::number(clock.mins()));
        ui->hourLabel->setText(QString::number(clock.hrs()));
    }
}























