#include "rockreb.h"

rockreb::rockreb(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr)
{
    setPixmap(QPixmap(":/images/rock.png"));
    if(modelo_==0){
        modelos.append(new Fisica(px_,py_,vx_,vy_,modelo_));
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(posicionar1()));
        timer->start(30);

    }
    else if(modelo_==1){
        modelos.append(new Fisica(px_,py_,vx_,vy_,modelo_));
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(posicionar2()));
        timer->start(30);
    }
    setPos(px_,py_);
}

void rockreb::posicionar1()
{
   modelos.at(0)->modelos();
   setPos(modelos.at(0)->getPx(),modelos.at(0)->getPy());
   if(modelos.at(0)->getPx()<0){
       modelos.at(0)->setVx(-modelos.at(0)->getVx());
   }
   else if(modelos.at(0)->getPx()>820){
       modelos.at(0)->setVx(-modelos.at(0)->getVx());
   }
   else if(modelos.at(0)->getPy()<0){
       modelos.at(0)->setVy(-modelos.at(0)->getVy());
   }
   else if(modelos.at(0)->getPy()>400){
       modelos.at(0)->setVy(-modelos.at(0)->getVy());
   }
}

void rockreb::posicionar2()
{
    modelos.at(0)->modelos();
    setPos(modelos.at(0)->getPx(),modelos.at(0)->getPy());
    if(modelos.at(0)->getPy()>520){
        scene()->removeItem(this);
        delete this;
    }
}
