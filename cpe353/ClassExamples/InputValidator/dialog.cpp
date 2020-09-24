#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QIntValidator* intValidator =
            new QIntValidator(ui->lineEdit);
    ui->lineEdit->setValidator(intValidator);

    QIntValidator* byteValidator = new QIntValidator(0, 255, ui->lineEdit_2);
    ui->lineEdit_2->setValidator(byteValidator);

    QRegularExpressionValidator* binValidator = new QRegularExpressionValidator(QRegularExpression("[01]{1,8}"), ui->lineEdit_3);
    ui->lineEdit_3->setValidator(binValidator);

    QRegularExpressionValidator* hexValidator = new QRegularExpressionValidator(QRegularExpression("[1-9A-Fa-f]{1,2}"), ui->lineEdit_4);
    ui->lineEdit_4->setValidator(hexValidator);

    QDoubleValidator* doubleValidator = new QDoubleValidator(-100.0, 100.0, 1, ui->lineEdit_5);
    ui->lineEdit_5->setValidator(doubleValidator);

    QRegularExpressionValidator* lowerValidator = new QRegularExpressionValidator(QRegularExpression("[a-z]{1,15}"), ui->lineEdit_6);
    ui->lineEdit_6->setValidator(lowerValidator);

    QRegularExpressionValidator* mixedValidator = new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]{1,15}"), ui->lineEdit_7);
    ui->lineEdit_7->setValidator(mixedValidator);

    QRegularExpression phone("[0-9]{3}-[0-9]{3}-[0-9]{4}");
    QRegularExpressionValidator* phoneVal = new QRegularExpressionValidator(phone, ui->lineEdit_8);
    ui->lineEdit_8->setValidator(phoneVal);
}

Dialog::~Dialog()
{
    delete ui;
}
