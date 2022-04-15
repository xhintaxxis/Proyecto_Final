#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,900,480);
    ui->graphicsView->setScene(scene);

        botton * playboton = new botton(QString("Nueva Partida"));
        int xj = this->width()/2 -playboton->boundingRect().width()/2;
        playboton->setPos(xj,240);
        scene->addItem(playboton);

        botton * loadboton = new botton(QString("Cargar"));
        int xl = this->width()/2 -loadboton->boundingRect().width()/2;
        loadboton->setPos(xl,320);
        scene->addItem(loadboton);

        botton * quitButton = new botton(QString("Salir"));
        int qxPos = this->width()/2 -quitButton->boundingRect().width()/2;
        quitButton->setPos(qxPos,400);
        //connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
        ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/fondo portada.png"))));
        titulo = new QGraphicsPixmapItem();
        titulo->setPixmap(QPixmap(":/images/titulo.png"));
        titulo->setPos(294,100);
        scene->addItem(titulo);
        connect(playboton,SIGNAL(click()),this,SLOT(pre1()));
        connect(quitButton,SIGNAL(click()),this,SLOT(close()));
          nave= new cuerpo(200,200,0,0,0,scene);
          scene->addItem(nave);
          nave->setFlag(QGraphicsItem::ItemIsFocusable);
          nave->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::moverPruebas()
{
//    int pyie1[]={100,200,500};
//    srand(time(NULL));
//    float pye3 = 50 + rand()%(400-50);
//    float pye1 =rand()%100;
//   qDebug()<<pye3;
//   qDebug()<<pye1;
//    enemy = new Enemigo_1(1000,pye1,-5,0,0,1,0);
//    scene->addItem(enemy);
//    enemy2 = new enemigo_3(0,pye3,50);
//    scene->addItem(enemy2);

}

void MainWindow::escena_1()
{

}

void MainWindow::pre1()
{
    scene->removeItem(nave);
    free(nave);
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/fondo cambio de nivel.jpg"))));
}

