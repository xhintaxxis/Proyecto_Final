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
    show();
    ventana = new inicioSesion();
    ventana->show();
    connect(ventana,SIGNAL(aceptar()),this,SLOT(preMenu()));
//    ventana->close();
//    delete ventana;
//    menu();
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

    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/oceno.gif"))));
    scen1 = new QTimer();
    connect(scen1,SIGNAL(timeout()),this,SLOT(enemigosS1()));
    scen1->start(3000);
    nave = new cuerpo(100,230,0,0,0,scene,0);
    scene->addItem(nave);
    lose = new QTimer();
    connect(lose,SIGNAL(timeout()),this,SLOT(gameOver()));
    lose->start(60);
    jefe1timer= new QTimer();
    connect( jefe1timer,SIGNAL(timeout()),this,SLOT(scenaBoss1()));
    jefe1timer->start(60000);

}

void MainWindow::pre1()
{
    escena=1;
    delete titulo;
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/oceno.gif"))));
    comenzar = new botton(QString("Comenzar"));
    int xc = this->width()/2 -comenzar->boundingRect().width()/2;
    comenzar->setPos(xc,320);
    scene->addItem(comenzar);
    stage1 = new QGraphicsPixmapItem();
    stage1->setPixmap(QPixmap(":/images/Cool Text - AREA   1     OCEANO 408817294775381.png"));
    stage1->setPos(120,0);
    scene->addItem(stage1);
    connect(comenzar,SIGNAL(click()),this,SLOT(escena_1()));

}

void MainWindow::enemigosS1()
{
    if(cambio==1){
        enemy = new Enemigo_1(1000,50,-10,0,0,0,0);
        scene->addItem(enemy);
        enemy12 = new Enemigo_1(1000,410,-10,0,0,0,0);
        scene->addItem(enemy12);
        enemy2 =new enemigo_2(900,70,-3,0,0);
        scene->addItem(enemy2);
        cambio=2;
    }
    else if(cambio==2){
        cambio=3;
        enemy = new Enemigo_1(1000,50,-10,0,0,0,0);
        scene->addItem(enemy);
        enemy12 = new Enemigo_1(1000,410,-10,0,0,0,0);
        scene->addItem(enemy12);
        Enemigo_1 * enemy13 = new Enemigo_1(1000,130,-10,0,0,0,0);
        scene->addItem(enemy13);
        Enemigo_1 * enemy14 = new Enemigo_1(1000,230,-10,0,0,0,0);
        scene->addItem(enemy14);
        Enemigo_1 * enemy15 = new Enemigo_1(1000,330,-10,0,0,0,0);
        scene->addItem(enemy15);
    }

    else if(cambio==3){
            cambio=1;
            enemy2 =new enemigo_2(900,50,-11,0,0);
            scene->addItem(enemy2);
            enemigo_2 * enemy21 =new enemigo_2(900,230,-11,0,0);
            scene->addItem(enemy21);
    }
}



void MainWindow::gameOver()
{
    if(nave->vida<1){
        delete nave;
        //delete enemy;
        //delete enemy2;
        //delete  enemy12;
        scen1->stop();
        lose->stop();
        scene->clear();
        jefe1timer->stop();
        menu();
    }
    if(passBoss==1){
        if(boss1->vida<1){
            scene->removeItem(boss1);
            delete boss1;
            //delete  nave;
            passBoss=0;
            scene->clear();
            escena=2;
            saveScene();
            lose->stop();

        }
    }
    if(passBoss==2){
        if(boss2->vida<1){
            scene->removeItem(boss2);
            delete boss2;
            //delete  nave;
            //qDebug()<<"termino";
            passBoss=0;
            scene->clear();
            escena=3;
            saveScene();           
            lose->stop();
            qDebug()<<"termino";
        }

    }
}

void MainWindow::menu()
{
    scene->clear();
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
    connect(loadboton,SIGNAL(click()),this,SLOT(cargar()));
}

void MainWindow::scenaBoss1()
{
    boss1 = new jefe1(600,190,0,5,0);
    scene->addItem(boss1);
    jefe1timer->stop();
    passBoss=1;
    scen1->stop();
}

void MainWindow::scenaBoss2()
{
    boss2 = new jefe2();
    scene->addItem(boss2);
    jefe1timer->stop();
    passBoss=2;
    scen1->stop();
}

void MainWindow::saveScene()
{
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/fondo stage clear.jpg"))));

    guardar = new botton(QString("Guardar"));
    int xg = this->width()/2 -guardar->boundingRect().width()/2;
    guardar->setPos(xg,280);
    scene->addItem(guardar);
    connect(guardar,SIGNAL(click()),this,SLOT(save()));

    completado = new QGraphicsPixmapItem();
    completado->setPixmap(QPixmap(":/images/nivel completado.png"));
    completado->setPos(215,100);
    scene->addItem(completado);

    botton * next = new botton(QString("Siguiente Nivel"));
    int xs = this->width()/2 -next->boundingRect().width()/2;
    next->setPos(xs,340);
    scene->addItem(next);
    qDebug()<<escena;
    if(escena==2){
        connect(next,SIGNAL(click()),this,SLOT(pre2()));
    }
    else if(escena==3){
        connect(next,SIGNAL(click()),this,SLOT(pre3()));
    }


}

void MainWindow::pre2()
{
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/cueva.jpg"))));
    stage1 = new QGraphicsPixmapItem();
    stage1->setPixmap(QPixmap(":/images/Area 2 cueva.png"));
    stage1->setPos(135,0);
    scene->addItem(stage1);
    comenzar = new botton(QString("Comenzar"));
    int xs = this->width()/2 -comenzar->boundingRect().width()/2;
    comenzar->setPos(xs,340);
    scene->addItem(comenzar);
    connect(comenzar,SIGNAL(click()),this,SLOT(escena_2()));
}

void MainWindow::escena_2()
{
    cambio=1;
    scene->clear();
    scen1 = new QTimer();
    connect(scen1,SIGNAL(timeout()),this,SLOT(enemigosS2()));
    scen1->start(3000);
    nave = new cuerpo(100,230,0,0,0,scene,0);
    scene->addItem(nave);
    lose = new QTimer();
    connect(lose,SIGNAL(timeout()),this,SLOT(gameOver()));
    lose->start(60);
    jefe1timer= new QTimer();
    connect( jefe1timer,SIGNAL(timeout()),this,SLOT(scenaBoss2()));
    jefe1timer->start(40000);
//    jefe2 * boss2 = new jefe2();
//    scene->addItem(boss2);
}

void MainWindow::save()
{
    write.clear();
    QFile file;
    file.setFileName("C:/Users/Angel/OneDrive/Documentos/C++/Laboratorio_4/Inicio_juego/texto/cargar.txt");
   // QFile file(":/texto/cargar.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i=0;i<loadline.size();i++){
        if(i==posicion){
            if(escena==2){
               write.append("2");
             }
            else if(escena==3){
               write.append("3");
             }
        }
        else{
            write.append((loadline.at(i).toStdString()));
        }

    }
    for(int i = 0;i<write.size();i++){
        qDebug()<<write.at(i);
    }
    write.append(",");
    qDebug()<<write;
    file.write(write);
    file.close();

}

void MainWindow::cargar()
{
 escena=loadline.at(posicion).toInt();
    if(escena==1){
        pre1();
    }
    if(escena==2){
        pre2();
    }
    if (escena==3){
        pre3();
    }
}


void MainWindow::preMenu()
{
    posicion=ventana->nivel;
    qDebug()<<posicion;
    delete ventana;
    menu();
    preLoad();

}

void MainWindow::preLoad()
{
    QString info;
    QFile file(":/texto/cargar.txt");
    file.open(QIODevice::ReadOnly);
    info = file.readLine();
    int n=0;
    while (true){
        if(info.at(n)==char(44)){
            break;
        }
        loadline.append(info.at(n));
        //qDebug()<<loadline.at(n);
        n++;
    }
    qDebug()<<loadline.at(posicion);
    file.close();

}

void MainWindow::enemigosS2()
{
    if(cambio==1){
        enemigo_2 * enemy21 = new enemigo_2(1100,50,-11,0,0);
        scene->addItem(enemy21);
        enemigo_2 * enemy22 =new enemigo_2(1100,230,-11,0,0);
        scene->addItem(enemy22);
        cambio=2;
    }
    else if(cambio==2){
        enemigo_2 * enemy21 = new enemigo_2(1070,50,-11,0,0);
        scene->addItem(enemy21);
        Obstaculo * obs1 = new Obstaculo(1130,250,-11,0,0);
        scene->addItem(obs1);
        cambio=3;
    }
    else if(cambio==3){
        enemigo_2 * enemy21 = new enemigo_2(1070,250,-8,0,0);
        scene->addItem(enemy21);
        Obstaculo * obs1 = new Obstaculo(1130,50,-8,0,0);
        scene->addItem(obs1);
        cambio=4;
    }
    else if(cambio==4) {
        Obstaculo * obs1 = new Obstaculo(1130,0,-8,0,0);
        scene->addItem(obs1);
        Obstaculo * obs2 = new Obstaculo(1130,290,-8,0,0);
        scene->addItem(obs2);
        cambio=5;
    }
    else if(cambio==5) {
        enemy = new Enemigo_1(1000,50,-10,0,0,0,0);
        scene->addItem(enemy);
        enemy12 = new Enemigo_1(1000,410,-10,0,0,0,0);
        scene->addItem(enemy12);
        Enemigo_1 * enemy13 = new Enemigo_1(1000,130,-10,0,0,0,0);
        scene->addItem(enemy13);
        Enemigo_1 * enemy14 = new Enemigo_1(1000,230,-10,0,0,0,0);
        scene->addItem(enemy14);
        Enemigo_1 * enemy15 = new Enemigo_1(1000,330,-10,0,0,0,0);
        scene->addItem(enemy15);
        cambio=1;

    }

}

void MainWindow::pre3()
{
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush((QImage(":/images/nocturnoespacio.jpg"))));
    comenzar = new botton(QString("Comenzar"));
    int xc = this->width()/2 -comenzar->boundingRect().width()/2;
    comenzar->setPos(xc,320);
    scene->addItem(comenzar);
    stage1 = new QGraphicsPixmapItem();
    stage1->setPixmap(QPixmap(":/images/area 3.png"));
    stage1->setPos(120,0);
    scene->addItem(stage1);
    connect(comenzar,SIGNAL(click()),this,SLOT(escena_3()));
}

void MainWindow::escena_3()
{
    cambio=1;
    scene->clear();
    scen1 = new QTimer();
    connect(scen1,SIGNAL(timeout()),this,SLOT());
    scen1->start(3000);
    nave = new cuerpo(100,230,0,0,0,scene,0);
    scene->addItem(nave);
    lose = new QTimer();
   // connect(lose,SIGNAL(timeout()),this,SLOT(gameOver()));
    lose->start(60);
    jefe1timer= new QTimer();
    connect( jefe1timer,SIGNAL(timeout()),this,SLOT());
    jefe1timer->start(1000);
    boss3 = new jefe3(900,0,-3,0,0);
    scene->addItem(boss3);
    bolafuego * ballfire = new bolafuego();
    scene->addItem(ballfire);
    Enemigo_1 * prueba = new Enemigo_1(900,300,-5,-5,0,0,0);
    scene->addItem(prueba);
}



