#include "bolafuego.h"

bolafuego::bolafuego(QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/images/bolafuego.png"));
    this->setPos(cx+ampx,cy);
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    qDebug()<<"hola";
    timer->start(10);
}

void bolafuego::posicionar()
{
    movimiento();
    setPos(px,py);
}

void bolafuego::movimiento()
{
    px=ampx*cos(theta)+cx;
    py=ampy*sin(theta)+cy;
    theta+=0.01;
    ampx=ampx+ampxdt;
    if(ampx>300){
        ampxdt=-ampxdt;
    }
    else if(ampx<100){
        ampxdt=-ampxdt;
    }
}
