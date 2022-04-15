#include "enemigo_1.h"

Enemigo_1::Enemigo_1(float px_, float py_, float vx_, float vy_, int modelo_,int douP, QGraphicsItem *carr)
{
    movimiento=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/e_1.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
    timer->start(30);
//    QTimer * timerP = new QTimer();
//    connect(timerP,SIGNAL(timeout()),this,SLOT(proyectil()));
//    timerP->start(2000);
    if (douP==0){
        QTimer * timerP = new QTimer();
        connect(timerP,SIGNAL(timeout()),this,SLOT(proyectil()));
        timerP->start(2000);
    }
    else{
        QTimer * timerP = new QTimer();
        connect(timerP,SIGNAL(timeout()),this,SLOT(douProyectil()));
        timerP->start(2000);
    }
}

Fisica *Enemigo_1::getMovimiento() const
{
    return movimiento;
}

void Enemigo_1::posicionar()
{
    setPos(movimiento->getPx(),movimiento->getPy());
}

void Enemigo_1::mover()
{

    setPos(movimiento->getPx(),movimiento->getPy());
    movimiento->modelos();
    if(movimiento->getPx()<-100){
        scene()->removeItem(this);
        delete this;
    }
}

void Enemigo_1::proyectil()
{
    bomba * bomba1 = new bomba(movimiento->getPx(),movimiento->getPy(),-7,2,1);
    scene()->addItem(bomba1);
}

void Enemigo_1::douProyectil()
{
    if(Cambio==false){
        bomba * bomba1 = new bomba(movimiento->getPx(),movimiento->getPy(),-7,2,1);
        scene()->addItem(bomba1);
        Cambio=true;
    }
    else if(Cambio==true){
        rayoE * bala = new rayoE(movimiento->getPx(),movimiento->getPy()+30,-10,0,0);
        scene()->addItem(bala);
        Cambio=false;

    }

}

