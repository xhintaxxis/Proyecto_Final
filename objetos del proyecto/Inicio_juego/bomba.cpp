#include "bomba.h"

bomba::bomba(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    parabolico = new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/bomba.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(30);
}

void bomba::posicionar()
{
    parabolico->modelos();
    setPos(parabolico->getPx(),parabolico->getPy());
    if(parabolico->getPy()>500){
        scene()->removeItem(this);
        delete this;
    }
}


