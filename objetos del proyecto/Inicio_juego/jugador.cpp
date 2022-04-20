#include "jugador.h"
#include "QKeyEvent"

jugador::jugador(QGraphicsScene *scene, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    modefi = new Fisica(0,250,0,0,0);
    setPixmap(QPixmap(":/images/New Piskel.png"));
    setPos(90,90);
    heart = new corazon();
    scene->addItem(heart);

}

void jugador::garbage()
{
    free(heart);

}

