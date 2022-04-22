#include "jefe1.h"

jefe1::jefe1(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    uniforme=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/jefe1.png"));
    this->setPos(px_,py_);
//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
//    timer->start(30);
    timers.append(new QTimer());
    connect(timers.at(0),SIGNAL(timeout()),this,SLOT(posicionar()));
    timers.at(0)->start(30);
//    timer2 = new QTimer();
//    connect(timer2,SIGNAL(timeout()),this,SLOT(proyectil()));
//    timer2->start(1100);
    timers.append(new QTimer());
    connect(timers.at(1),SIGNAL(timeout()),this,SLOT(proyectil()));
    timers.at(1)->start(1100);
//    timers.append(new QTimer());
//    connect(timers.at(2),SIGNAL(timeout()),this,SLOT(posicionar()));
//    timers.at(2)->start(1);

}

void jefe1::posicionar()
{
    if(uniforme->getPy()>270){
        uniforme->setVy(-5);
    }
    else if(uniforme->getPy()<0){
        uniforme->setVy(5);
    }
    uniforme->modelos();
    setPos(uniforme->getPx(),uniforme->getPy());
    QList<QGraphicsItem *> colisionBala =collidingItems();
    for(int i =0;i<colisionBala.size();i++){
        if(typeid (*colisionBala.at(i))==typeid (rayo)){
            scene()->removeItem(colisionBala.at(i));
            delete colisionBala.at(i);
            vida--;
        }
    }
//    if(vida<1){
//        scene()->removeItem(this);
//        delete this;
//    }

}

void jefe1::proyectil()
{
    static long int cont=0;
    bala.append(new rayoE(uniforme->getPx()-10,uniforme->getPy(),-5,0,0));
    scene()->addItem(bala.at(bala.size()-1));
    bala.append(new rayoE(uniforme->getPx()-10,uniforme->getPy()+105,-5,0,0));
    scene()->addItem(bala.at(bala.size()-1));
    bala.append(new rayoE(uniforme->getPx()-10,uniforme->getPy()+210,-5,0,0));
    scene()->addItem(bala.at(bala.size()-1));

//    rayoE * rayo1 = new rayoE(uniforme->getPx()-10,uniforme->getPy(),-5,0,0);
//    scene()->addItem(rayo1);
//    rayoE * rayo2 = new rayoE(uniforme->getPx()-10,uniforme->getPy()+105,-5,0,0);
//    scene()->addItem(rayo2);
//    rayoE * rayo3 = new rayoE(uniforme->getPx()-10,uniforme->getPy()+220,-5,0,0);
    //    scene()->addItem(rayo3);
    if(cont==3){
        bomb.append(new bomba(500,-60,-7,0,1));
        scene()->addItem(bomb.at(bomb.size()-1));
        bomb.append(new bomba(700,-60,-7,0,1));
        scene()->addItem(bomb.at(bomb.size()-1));
        bomb.append(new bomba(900,-60,-7,0,1));
        scene()->addItem(bomb.at(bomb.size()-1));
        cont=0;
    }
    else{
        cont++;
    }
}

void jefe1::proyectil2()
{

}
