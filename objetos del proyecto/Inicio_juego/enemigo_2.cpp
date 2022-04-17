#include "enemigo_2.h"

enemigo_2::enemigo_2(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *car)
{
    uniforme = new Fisica(px_,py_,vx_,vy_,modelo_);
    setPixmap(QPixmap(":/images/e_2.png"));
    this->setPos(px_,py_);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(30);
}

void enemigo_2::posicionar()
{
    uniforme->modelos();
    setPos(uniforme->getPx(),uniforme->getPy());
    QList<QGraphicsItem * > enemy2col=collidingItems();
    for(int i = 0; i<enemy2col.size();i++){
        if(typeid(*enemy2col.at(i))==typeid (rayo)){
            vida--;
            scene()->removeItem(enemy2col.at(i));
            delete enemy2col.at(i);
        }
    }
    if (vida==0){
        scene()->removeItem(this);
        delete this;
    }
    if(uniforme->getPx()<(-400)){
        scene()->removeItem(this);
        delete this;
    }
}
