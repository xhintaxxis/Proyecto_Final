#include "jefe3.h"

jefe3::jefe3(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    uniforme=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/jefe3.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(18);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(proyectiles()));
    timer2->start(600);
    //x
    //y
    //vx
    //vy

}

void jefe3::posicionar()
{
    uniforme->modelos();
    setPos(uniforme->getPx(),uniforme->getPy());
    if(uniforme->getPx()>620 and uniforme->getPy()<=0){
        uniforme->setVx(-7);
        uniforme->setVy(0);
        cambio=1;
        corrector=1;
    }
    else if(uniforme->getPy()<200 and cambio==1){
        uniforme->setVx(2);
        uniforme->setVy(4);
    }
    else if(uniforme->getPy()>=200 and uniforme->getPx()>620 and corrector==1){
        uniforme->setVx(-7);
        uniforme->setVy(0);
        cambio=2;
    }
    else{
        uniforme->setVx(2);
        uniforme->setVy(-4);
        corrector=2;
    }

}

void jefe3::proyectiles()
{
    if(balacambio==1){
        rayoE * bala = new rayoE(uniforme->getPx(),uniforme->getPy()+80,-4,0,0);
        scene()->addItem(bala);
        balacambio=2;
    }
    else if(balacambio==2){
        rayoE * bala = new rayoE(uniforme->getPx(),uniforme->getPy()+120,-4,1,0);
        scene()->addItem(bala);
        balacambio=3;
    }
    else if(balacambio==3){
        rayoE * bala = new rayoE(uniforme->getPx(),uniforme->getPy()+120,-4,-1,0);
        scene()->addItem(bala);
        balacambio=1;
    }

}
