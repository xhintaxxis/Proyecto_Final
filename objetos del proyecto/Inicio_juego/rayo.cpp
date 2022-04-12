#include "rayo.h"


rayo::rayo(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    modelo_=0;
    uniforme=new Fisica(px_,py_,vx_,vy_,modelo_);
    pxi=px_;
    pyi=py_;
    setPixmap(QPixmap(":/images/rayo.png"));
    setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
    timer->start(30);
}

void rayo::mover()
{
   uniforme->modelos();
   setPos(uniforme->getPx(),uniforme->getPy());
   if(uniforme->getPx()-pxi>450){
       scene()->removeItem(this);
       delete this;
   }

}
