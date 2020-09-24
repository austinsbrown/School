#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dialog::edit);
    connect(ui->clearButton, &QPushButton::clicked, this, &Dialog::clear);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::edit()
{
    QString s = ui->lineEdit->text();

    ui->outputEdit->setText(s);
    ui->outputLabel->setText(s);
}


void Dialog::clear()
{
    ui->lineEdit->clear();
}
