#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::fileLoad);
    ui->filteredEdit->installEventFilter(this);

    stat = new QLabel(this);
    ui->statusBar->addWidget(stat);

    QRegularExpression s("[0-9]{1}[A-Z]{1}[.]{1}[t]{1}[x]{1][t]{1}");
    valid = new QRegularExpressionValidator(s, this);
    ui->fileNameEdit->setValidator(valid);

    options = menuBar()->addMenu("Options");
    NonModal = new QAction("NonModal", this);

    options->addAction(NonModal);
    ui->mainToolBar->addAction(NonModal);

    connect(NonModal, &QAction::triggered, this, &MainWindow::nonModal);

    connect(ui->spinboxQt5, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &MainWindow::setDial);
    connect(ui->dialQt5, &QDial::valueChanged, this, &MainWindow::setSpin);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fileLoad()
{
    QFile file("out.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    QString s = ui->fileEdit->toPlainText();
    out << s;


}


bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{
    if(!watched || !e) return QWidget::eventFilter(watched, e);
    {
        if(watched == ui->filteredEdit && e->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(e);
            if(ke->key() == Qt::Key_Delete)
            {
                stat->setText("Delete");
            }

            else if(ke->key() == Qt::Key_Insert)
            {
               stat->setText("Insert");
            }

        }
    }
    return QMainWindow::eventFilter(watched, e);
}


void MainWindow::nonModal()
{
    QDialog *x = new QDialog(this);
    QVBoxLayout *l = new QVBoxLayout(this);
    QPushButton *p = new QPushButton;
    p->setText("Close");
    x->setLayout(l);
    l->addWidget(p);
    x->show();
    connect(p, &QPushButton::clicked, x, &QDialog::accept);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::RightButton)
    {
        qDebug() << "right button is pressed";
    }
}


void MainWindow::setDial()
{
   int x = ui->spinboxQt5->value();
   ui->dialQt5->setValue(x);
}


void MainWindow::setSpin()
{
    int x = ui->dialQt5->value();
    ui->spinboxQt5->setValue(x);
}













