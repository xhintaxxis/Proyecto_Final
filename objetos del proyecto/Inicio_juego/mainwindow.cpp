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
    scene->addRect(scene->sceneRect());
    nave = new cuerpo(0,0,0,0,0,scene);
    setFixedSize(900,480);
    cuadro = new QGraphicsRectItem(0,0,20,20);
    scene->addItem(cuadro);
    nave->posicionar();
    scene->addItem(nave);
    enemy = new Enemigo_1(0,-50,5,2,0);
    scene->addItem(enemy);
    nave1=new jugador();
    enemy2 = new enemigo_3(0,50,50);
    scene->addItem(enemy2);
    nave1->setRect(nave1->getUniforme()->getPx(),nave1->getUniforme()->getPy(),100,100);
    scene->addItem(nave1);
    ball = new bolafuego();
    scene->addItem(ball);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(moverPruebas()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case  Qt::Key_D:{
        nave->getModefi()->setVx(7);
        nave->getModefi()->modelos();
        //nave->setPos(nave->getModefi()->getPx(),nave->getModefi()->getPy());
        nave->posicionar();
        break;
    }
    case  Qt::Key_A:{
        nave->getModefi()->setVx(-7);
        nave->getModefi()->modelos();
        //nave->setPos(nave->getModefi()->getPx(),nave->getModefi()->getPy());
        nave->posicionar();
        break;
    }
    case  Qt::Key_S:{
        nave->getModefi()->setVy(7);
        nave->getModefi()->modelos();
        //nave->setPos(nave->getModefi()->getPx(),nave->getModefi()->getPy());
        nave->posicionar();
        break;
    }
    case  Qt::Key_W:{
        nave->getModefi()->setVy(-7);
        nave->getModefi()->modelos();
        //nave->setPos(nave->getModefi()->getPx(),nave->getModefi()->getPy());
        nave->posicionar();
        break;
    }
    case  Qt::Key_Space:{
        nave->proyectil();
        ui->graphicsView->scale(0.5,0.5);
        break;
    }
    default: break;
    }
    nave->getModefi()->setVx(0);
    nave->getModefi()->setVy(0);
}

void MainWindow::moverPruebas()
{
    //enemy->getMovimiento()->modelos();
    //enemy->posicionar();
    static int cont=0;
    if (cont%3==0){
        enemy->getMovimiento()->modelos();
        enemy->posicionar();
        //ball->posicionar();
        //cont=0;
        if(cont%6==0){ball->posicionar();}
        if(cont==300){
            timer->stop();
        }
    }
    enemy2->getOscilacion()->modelos();
    enemy2->posicionar();
    cont++;
    qDebug()<<"entra";
}

