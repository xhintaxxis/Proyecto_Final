#include "bomba.h"

bomba::bomba(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    parabolico = new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/bomba.png"));
    this->setPos(px_,py_);
}

void bomba::posicionar()
{
    setPos(parabolico->getPx(),parabolico->getPy());
}


