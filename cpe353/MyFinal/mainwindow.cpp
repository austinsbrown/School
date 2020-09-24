#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projectile.h"


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

    scene= new QGraphicsScene(-1024/2, -768/2, 1024, 768);
    scene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(scene);

    if(!db.open())
    {
        qDebug() <<"Cannot open database";
    }

    QSqlQuery q;
    if(q.exec("SELECT * FROM walls"))
    {
        while (q.next())
        {
            walls= new QGraphicsRectItem(q.value(0).toInt(), q.value(1).toInt(),
                                         q.value(2).toInt(), q.value(3).toInt());
            walls->setBrush(QBrush(Qt::blue));
            this->scene->addItem(walls);
        }
    }

    if(q.exec("SELECT * FROM player"))
    {
        while (q.next())
        {
            pix= new QPixmap;
            pix->loadFromData(q.value(1).toByteArray());
            catpixs.append(pix);
        }
    }

    if(q.exec("SELECT * FROM target"))
    {
        while (q.next())
        {
            temp_pellet= new Pellet(-q.value(1).toInt(), -q.value(1).toInt(), q.value(1).toInt(),
                                q.value(1).toInt(), q.value(1).toInt(), &points);
            temp_pellet->setPos(q.value(1).toInt(), q.value(1).toInt());
            temp_pellet->setBrush(QBrush(Qt::green));
            scene->addItem(temp_pellet);
            pellets.append(temp_pellet);
        }
    }

    cat = new Cat(catpixs);
    scene->addItem(cat);

    timer= new QTimer(this);
    timer->setInterval(12);
    timer->start();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if(e!=nullptr)
    {

        if(e->key()==Qt::Key_Up)
        {
            notMoving = false;
            cat->direction("up");
        }
        else if(e->key()==Qt::Key_Left)
        {
            notMoving = false;
            cat->direction("left");
        }
        else if(e->key()==Qt::Key_Down)
        {
            notMoving = false;
            cat->direction("down");
        }
        else if(e->key()==Qt::Key_Right)
        {
            notMoving = false;
            cat->direction("right");
        }

        else if(e->key() == Qt::Key_Space && notMoving == false)
        {
            //relative pos of player
            QPointF currentpos = cat->pos();

            //create the bullet
            //make bullet appear in middle of player
            //add to scene
            Bullet * bullet = new Bullet(cat->currentDirection, currentpos);
            scene->addItem(bullet);

        }

    }
    QMainWindow::keyPressEvent(e);

}
















