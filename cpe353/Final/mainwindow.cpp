#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("mike");
    db.setPort(33200);
    db.setDatabaseName("2019cpe35302");
    db.setUserName("cpe35302");
    db.setPassword("6help6me6");

    if(!db.open())
    {
        qDebug() << "Error: Unable to open MySQL Db";
        exit(1);
    }
    else
    {
        //create the scene
        scene = new QGraphicsScene(0, 0, XMAX, YMAX, this);

        //make black background
        scene->setBackgroundBrush(QBrush(Qt::black));

        //set lines as borders
        QGraphicsLineItem * line1 = new QGraphicsLineItem(0, 0, XMAX, 0);
        QGraphicsLineItem * line2 = new QGraphicsLineItem(0, 0, 0, YMAX);
        QGraphicsLineItem * line3 = new QGraphicsLineItem(XMAX, YMAX, XMAX, 0);
        QGraphicsLineItem * line4 = new QGraphicsLineItem(XMAX, YMAX, 0, YMAX);

        line1->setPen(QPen(QColor(Qt::red),3));
        line2->setPen(QPen(QColor(Qt::white),3));
        line3->setPen(QPen(QColor(Qt::blue),3));
        line4->setPen(QPen(QColor(Qt::yellow),3));

        scene->addItem(line1);
        scene->addItem(line2);
        scene->addItem(line3);
        scene->addItem(line4);

        //set fixed screen size
        ui->graphicsView->setFixedSize(XMAX+50, YMAX+50);

        //create and setup player instance
        Player * player = new Player();
        player->setPos(XMAX/2, YMAX/2);
        scene->addItem(player);

        //To make Key events work i need to foucs the item
        player->setFlag(QGraphicsItem::ItemIsFocusable); //makes it able to be focused
        player->setFocus(); //set to the focused item

        //gets the locations of all enemys to set
        QSqlQuery query;

        int x;
        int y;

        int w;
        int h;
        //make the enemy
        for(int i = 0; i < 6; i ++) {
            x = rand() % 600 + (-300);
            y = rand() % 600 + (-300);

            w = rand() % 5 + 1;
            h = rand() % 5 + 1;

            Enemy * e = new Enemy(x, y, w, h);
            scene->addItem(e);

        }

        //add the scene to the graphicsView
        ui->graphicsView->setScene(scene);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
