#include "cuerpo.h"


Fisica *cuerpo::getModefi() const
{
    return modefi;
}

void cuerpo::proyectil()
{
    rayo * bala;
    bala = new rayo(modefi->getPx()+70,modefi->getPy()+7,8,0,0);
    scene()->addItem(bala);
}

cuerpo::cuerpo(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsScene* scene, QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    modelo_=0;
    modefi=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/New Piskel.png"));
}

void cuerpo::posicionar()
{
    setPos(modefi->getPx(),modefi->getPy());
}

void cuerpo::keyPressEvent(QKeyEvent *event)
{
}

