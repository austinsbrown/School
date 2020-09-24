#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->quitButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui->clearButton, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);
    connect(ui->BinaryButton, &QPushButton::clicked, this, &Dialog::makeBinary);
    connect(ui->HexButton, &QPushButton::clicked, this, &Dialog::makeHex);
    connect(ui->OcatlButton, &QPushButton::clicked, this, &Dialog::makeOctal);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::makeOctal()
{
    QString s = ui->lineEdit->text();
    ui->answerLabel->setText(s.number(s.toInt(), 8));
}


void Dialog::makeBinary()
{
    QString s = ui->lineEdit->text();
    ui->answerLabel->setText(s.number(s.toInt(), 2));
}


void Dialog::makeHex()
{
    QString s = ui->lineEdit->text();
    ui->answerLabel->setText(s.number(s.toInt(), 16));
}
