#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(reset));
    connect(ui->spinBox1, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Dialog::add);
    connect(ui->spinBox2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Dialog::add);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::reset()
{
    ui->spinBox1->setValue(0);
    ui->spinBox2->setValue(0);
}


void Dialog::add()
{
    int x = ui->spinBox1->value();
    int y = ui->spinBox2->value();
    int sum = x + y;
    ui->result->setText(QString::number(sum));
}
