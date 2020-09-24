#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->verticalSlider, &QSlider::valueChanged, this, &Dialog::slideX);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Dialog::slideY);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::slideX()
{
    int x = ui->verticalSlider->value();
    ui->horizontalSlider->setValue(x);
}


void Dialog::slideY()
{
    int x = ui->horizontalSlider->value();
    ui->verticalSlider->setValue(x);
}
