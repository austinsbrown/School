#include "modaldialog.h"
#include "ui_modaldialog.h"

ModalDialog::ModalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModalDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &ModalDialog::accept);
}

ModalDialog::~ModalDialog()
{
    delete ui;
}
