#include "bolafuego.h"

bolafuego::bolafuego(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/images/bolafuego.png"));
    circular = new Fisica();
    posicionar();
}

void bolafuego::posicionar()
{
    setPos(circular->getPx(),circular->getPy());
    circular->modelos();
}
