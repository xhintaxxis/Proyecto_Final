#include "enemigo_3.h"
#include "fisica.h"
Fisica *enemigo_3::getOscilacion() const
{
    return oscilacion;
}

void enemigo_3::parabolic()
{
    parabolico = new Fisica(900-oscilacion->getPx(),oscilacion->getPy(),-5,0,1);
    delete oscilacion;
    cambio=1;
}

void enemigo_3::posicionar()
{
    if(cambio==0){
    oscilacion->modelos();
    setPos(900-oscilacion->getPx(),oscilacion->getPy());
//    if(900-oscilacion->getPx()<-80){
//        scene()->removeItem(this);
//        delete this;
//    }
    if(900-oscilacion->getPx()<400){
        parabolic();
    }
    }
    else if (cambio==1){
        parabolico->modelos();
        setPos(parabolico->getPx(),parabolico->getPy());
        if(parabolico->getPx()<-80){
            scene()->removeItem(this);
            delete this;
        }
    }

}

enemigo_3::enemigo_3(float px_, float py_, float Ampli_, QGraphicsItem *carr)
{
    oscilacion = new Fisica(px_,py_,Ampli_);
    setPixmap(QPixmap(":/images/e_3.png"));
    this->setPos(1000,900);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(15);
}
