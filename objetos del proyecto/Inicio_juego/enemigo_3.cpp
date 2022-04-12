#include "enemigo_3.h"
#include "fisica.h"
Fisica *enemigo_3::getOscilacion() const
{
    return oscilacion;
}

void enemigo_3::posicionar()
{
    setPos(900-oscilacion->getPx(),oscilacion->getPy());
}

enemigo_3::enemigo_3(float px_, float py_, float Ampli_, QGraphicsItem *carr)
{
    oscilacion = new Fisica(px_,py_,Ampli_);
    setPixmap(QPixmap(":/images/e_3.png"));
    this->setPos(px_,py_);
}
