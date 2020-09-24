#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton, &QToolButton::clicked, this, &Widget::tool);
    connect(ui->toolButton_2, &QToolButton::clicked, this, &Widget::tool);
    connect(ui->toolButton_3, &QToolButton::clicked, this, &Widget::tool);
    connect(ui->toolButton_4, &QToolButton::clicked, this, &Widget::tool);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::printGo);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::printPause);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Widget::printStop);

    connect(ui->radioButton, &QRadioButton::clicked, this, &Widget::radio);

    connect(ui->pushButton_4, &QPushButton::clicked, this, &Widget::clearLineEdit);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Widget::printLineEdit);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::tool()
{
    qDebug() << "Tool Button";
}


void Widget::printGo()
{
    qDebug() << "Go";
}


void Widget::printPause()
{
    qDebug() << "Pause";
}


void Widget::printStop()
{
    qDebug() << "Stop";
}


void Widget::radio()
{
    if(ui->label_2->text() == "0")
    {
        ui->label_2->setText("1");
        qDebug() << "1";
    }
    else
    {
        ui->label_2->setText("0");
        qDebug() << "0";
    }
}


void Widget::clearLineEdit()
{
    ui->lineEdit->clear();
}


void Widget::printLineEdit()
{
    qDebug() << ui->lineEdit->text();
}
