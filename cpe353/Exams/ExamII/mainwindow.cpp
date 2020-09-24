#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "togglelabel.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // HINT: P02 - event filtering
    ui->filteredEdit->textCursor().insertText("1  ");
    ui->filteredEdit->installEventFilter(this);
    lineCount = 1;
    status = new QLabel(this);
    status->setText("Ready");
    status->setFrameStyle(1);
    statusBar()->addWidget(status);


    connect(ui->applyButton, &QPushButton::clicked, this, &MainWindow::protect);

    load2 = new QAction("Load", this);
    save2 = new QAction("Save", this);
    actionMenu = menuBar()->addMenu("File");
    actionMenu->addAction(load2);
    actionMenu->addAction(save2);
    connect(load2, &QAction::triggered, this, &MainWindow::load);
    connect(save2, &QAction::triggered, this, &MainWindow::save);

    ui->usernameEdit->setText("asb0034");
    connect(ui->spawnButton, &QPushButton::clicked, this, &MainWindow::spawn);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{
    if(!watched || !e) return QWidget::eventFilter(watched, e);

    if(watched == ui->filteredEdit && e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent*>(e);
        if(ke->key() == Qt::Key_Return)
        {
            lineCount++;
            ui->filteredEdit->textCursor().insertText('\n' + QString::number(lineCount) + "  ");
            status->setNum(lineCount);
            return true;

        }

        else if(ke->key() == Qt::Key_Enter)
        {
            lineCount++;
            ui->filteredEdit->textCursor().insertText('\n' + QString::number(lineCount) + "  ");
            status->setNum(lineCount);
            return true;

        }
    }
    return QMainWindow::eventFilter(watched, e);
}


void MainWindow::protect()
{
    ui->protectedEdit->clear();
    QRegularExpression s(ui->regexEdit->text());
    valid = new QRegularExpressionValidator(s, this);
    ui->protectedEdit->setValidator(valid);
}


void MainWindow::load()
{
    QStringList list;
    QString fileName = ui->fileNameEdit->text();
    QFile someFile(ui->fileNameEdit->text());
    int fileCount = 0;
    ui->fileNameEdit->clear();

    if(!someFile.exists())
    {
        QMessageBox msgBox;
        msgBox.setText("File I/O Error");
        msgBox.setInformativeText("File does not exist -- aborting load action");
        msgBox.exec();
    }

    else if(!someFile.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("File I/O Error");
        msgBox.setInformativeText("File is read or write only -- aborting load action");
        msgBox.exec();
    }

    else
    {

        QTextStream someStream(&someFile);
        QString someValue;
        while(!someStream.atEnd())
        {
            someValue = someStream.readLine();
            list.append(someValue);
            fileCount++;

        }

        int i = 0;
        ui->filteredEdit->textCursor().insertText(" " + list[i]);
        for(i=1; i < fileCount; i++)
        {
            lineCount++;
            ui->filteredEdit->textCursor().insertText('\n' + QString::number(lineCount) + "  " + list[i]);

        }
    }
}


void MainWindow::save()
{
    ui->fileNameEdit->clear();
    QStringList list;
    QString fileName = ui->fileNameEdit->text();
    QFile someFile(ui->fileNameEdit->text());
    int fileCount = 0;

    if(!someFile.exists())
    {
        QMessageBox msgBox;
        msgBox.setText("File I/O Error");
        msgBox.setInformativeText("File does not exist -- aborting load action");
        msgBox.exec();
    }

    else if(!someFile.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox msgBox;
        msgBox.setText("File I/O Error");
        msgBox.setInformativeText("File does not exist -- aborting load action");
        msgBox.exec();
    }

    else
    {
        QTextStream someStream(&someFile);
        QString someValue;





    }
}


void MainWindow::spawn()
{

    if(ui->nonmodalButton->isChecked())
    {
        QDialog *NonModDialog = new QDialog(this);
        ToggleLabel *toggle = new ToggleLabel;
        toggle->setFrameStyle(QFrame::WinPanel);
        //toggle->setPixmap(pm[0]);
        QHBoxLayout *l = new QHBoxLayout(this);
        QLabel *name = new QLabel;
        name->setText(ui->usernameEdit->text());
        NonModDialog->setLayout(l);
        l->addWidget(name);
        l->addWidget(toggle);
        NonModDialog->show();
        connect(ui->closeButton, &QPushButton::clicked, NonModDialog, &QDialog::accept);


    }

    else if(ui->modalButton->isChecked())
    {
        QDialog *ModDialog = new QDialog(this);
        ToggleLabel *toggle = new ToggleLabel;
        toggle->setFrameStyle(QFrame::WinPanel);
        //toggle->setPixmap(pm[0]);

        QHBoxLayout *l = new QHBoxLayout(this);
        QLabel *name = new QLabel;
        name->setText(ui->usernameEdit->text());
        ModDialog->setLayout(l);
        l->addWidget(name);
        l->addWidget(toggle);
        ModDialog->exec();
    }

}




















