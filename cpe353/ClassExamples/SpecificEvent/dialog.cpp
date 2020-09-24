#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::keyPressEvent(QKeyEvent *e)
{
    if(!e) return;

    if(e->key() == Qt::Key_Left)
    {
        ui->label->setText("Left");
    }
    else if (e->key() == Qt::Key_Right)
    {
        ui->label->setText("Right");
    }
    else if (e->key() == Qt::Key_Up)
    {
        ui->label->setText("Up");
    }
    else if (e->key() == Qt::Key_Down)
    {
        ui->label->setText("Down");
    }


    QDialog::keyPressEvent(e);
}
