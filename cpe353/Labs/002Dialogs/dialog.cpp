#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &Dialog::accept);
    connect(ui->modalButton, &QPushButton::clicked, this, &Dialog::modal);
    connect(ui->nonModalButton, &QPushButton::clicked, this, &Dialog::nonModal);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::modal()
{
    ModalDialog x;
    x.exec();
}


void Dialog::nonModal()
{
    NonModalDialog *x = new NonModalDialog(this);
    x->show();
}
