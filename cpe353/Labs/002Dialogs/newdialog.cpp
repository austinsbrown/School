#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &)
}

NewDialog::~NewDialog()
{
    delete ui;
}
