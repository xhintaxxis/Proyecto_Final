#include "enemigo_1.h"

Enemigo_1::Enemigo_1(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    movimiento=new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/e_1.png"));
    this->setPos(px_,py_);

}

Fisica *Enemigo_1::getMovimiento() const
{
    return movimiento;
}

void Enemigo_1::posicionar()
{
    setPos(movimiento->getPx(),-movimiento->getPy());
}
