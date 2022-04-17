#include "obstaculo.h"

Obstaculo::Obstaculo(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *car)
{
    unifome = new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/obstaculo.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(30);

}

void Obstaculo::posicionar()
{
    unifome->modelos();
    setPos(unifome->getPx(),unifome->getPy());
    if(unifome->getPx()<-70){
        scene()->removeItem(this);
        delete this;
    }
}
