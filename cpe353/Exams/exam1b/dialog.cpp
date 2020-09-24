#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QtDebug>
#include <QLabel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->mysteryButton->setText("asb0034");
    ui->toggleButton->setText("Disable");
    ui->lineEdit->setReadOnly(true);
    ui->columnLabel->setNum(1);
    ui->rowLabel->setNum(1);
    ui->rowDial->setValue(1);
    ui->columnDial->setValue(1);

    connect(ui->toggleButton, &QPushButton::clicked, this, &Dialog::changeButton);
    connect(ui->mysteryButton, &QPushButton::clicked, this, &Dialog::mysteryButton);

    connect(ui->resetButton, &QPushButton::clicked, this, &Dialog::reset);
    connect(ui->winnerButton, &QPushButton::clicked, this, &Dialog::processWinner);

    connect(ui->spawnButton, &QPushButton::clicked, this, &Dialog::createDialog);
    connect(ui->columnDial, &QDial::valueChanged, this, &Dialog::setLabels);
    connect(ui->rowDial, &QDial::valueChanged, this, &Dialog::setLabels);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::changeButton()
{
    if(ui->toggleButton->text() == "Disable")
    {
        ui->toggleButton->setText("Enable");
        ui->lineEdit->setReadOnly(false);
    }

    else if(ui->toggleButton->text() == "Enable")
    {
        ui->toggleButton->setText("Disable");
        ui->lineEdit->setReadOnly(true);
    }
}


void Dialog::mysteryButton()
{
    QString s = ui->lineEdit->text();
    if(ui->lineEdit->text() == "")
    {
        ui->mysteryButton->setText("BLANK");
    }
    else
    {
        ui->mysteryButton->setText(s);
    }

}


void Dialog::reset()
{
    if(ui->button1->isChecked())
    {
        ui->button1->click();
    }
    if(ui->button2->isChecked())
    {
        ui->button2->click();
    }
    if(ui->button3->isChecked())
    {
        ui->button3->click();
    }
    if(ui->button4->isChecked())
    {
        ui->button4->click();
    }
    if(ui->button5->isChecked())
    {
        ui->button5->click();
    }
    if(ui->button6->isChecked())
    {
        ui->button6->click();
    }
    if(ui->button7->isChecked())
    {
        ui->button7->click();
    }
    if(ui->button8->isChecked())
    {
        ui->button8->click();
    }
    if(ui->button9->isChecked())
    {
        ui->button9->click();
    }

}


void Dialog::processWinner()  // why
{
    if(ui->button1->isChecked() && ui->button4->isChecked() && ui->button7->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button2->isChecked() && ui->button5->isChecked() && ui->button8->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button3->isChecked() && ui->button6->isChecked() && ui->button9->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button1->isChecked() && ui->button2->isChecked() && ui->button3->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button4->isChecked() && ui->button5->isChecked() && ui->button6->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button7->isChecked() && ui->button8->isChecked() && ui->button9->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button1->isChecked() && ui->button5->isChecked() && ui->button9->isChecked())
    {
        emit updateStatus(true);
    }

    else if (ui->button3->isChecked() && ui->button5->isChecked() && ui->button7->isChecked())
    {
        emit updateStatus(true);
    }

    else
    {
        emit updateStatus(false);
    }
}


void Dialog::createDialog()
{
    int row = ui->rowDial->value();
    int col = ui->columnDial->value();

    QDialog *newDialog = new QDialog;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *grid = new QGridLayout;
    QPushButton *close = new QPushButton;
    close->setText("Close");
    connect(close, &QPushButton::clicked, newDialog, &QDialog::accept);

    newDialog->setLayout(mainLayout);
    mainLayout->addLayout(grid);
    mainLayout->addWidget(close);


    int count = 0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            QLabel *c = new QLabel;
            c->setFrameStyle(QFrame::Panel);

            c->setNum(count);
            grid->addWidget(c, i, j);
        }
        count++;
    }

    newDialog->show();
}


void Dialog::setLabels()
{
    ui->rowLabel->setNum(ui->rowDial->value());
    ui->columnLabel->setNum(ui->columnDial->value());
}


