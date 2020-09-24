#include "nonmodaldialog.h"
#include "ui_nonmodaldialog.h"

NonModalDialog::NonModalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NonModalDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &NonModalDialog::repeat);
}

NonModalDialog::~NonModalDialog()
{
    delete ui;
}


void NonModalDialog::repeat()
{
    NonModalDialog *x = new NonModalDialog(this);
    x->show();
}
