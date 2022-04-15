#include "rayoe.h"


rayoE::rayoE(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    Uniforme = new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/bala enemiga.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(30);
}

void rayoE::posicionar()
{
    Uniforme->modelos();
    setPos(Uniforme->getPx(),Uniforme->getPy());
    if (Uniforme->getPx()<-25){
        scene()->removeItem(this);
        delete this;
    }
}
