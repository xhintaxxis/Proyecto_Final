#include "jugador.h"
#include "QKeyEvent"
#include <QGraphicsScene>

jugador::jugador(QGraphicsItem *parent)
{
    uniforme= new Fisica(0,250,0,0,0);
}
void jugador::keyPressEvent(QKeyEvent *event){
    qDebug()<<"entra";
    setPos(500,0);
    switch (event->key()) {
    case  Qt::Key_D:{
        uniforme->setVx(3);
        uniforme->modelos();
        setPos(uniforme->getPx()+5,uniforme->getPy());
        break;
    }
    case  Qt::Key_A:{
        uniforme->setVx(-3);
        uniforme->modelos();
        setPos(uniforme->getPx()-5,uniforme->getPy());
        break;
    }
    default: break;
    }
}

Fisica *jugador::getUniforme() const
{
    return uniforme;
}

