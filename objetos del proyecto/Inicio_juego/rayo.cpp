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
   QList<QGraphicsItem*> enemyfall= collidingItems();
   //qDebug()<<enemyfall.size();

   for(int i =0 ; i<enemyfall.size();i++){
       if(typeid (*(enemyfall.at(i)))==typeid (Enemigo_1)){
         scene()->removeItem(enemyfall.at(i));
         delete enemyfall.at(i);
            enemyfall.clear();
           scene()->removeItem(this);
           delete  this;
           return;
       }
       else if(typeid (*(enemyfall.at(i)))==typeid (enemigo_3)){
           scene()->removeItem(enemyfall.at(i));
           delete enemyfall.at(i);
           enemyfall.clear();
             scene()->removeItem(this);
             delete  this;
             return;
       }
   }
   setPos(uniforme->getPx(),uniforme->getPy());
   if(uniforme->getPx()-pxi>450){
       enemyfall.clear();
       scene()->removeItem(this);
       delete this;
       return;
   }

}

bool rayo::getVacio() const
{
    return vacio;
}
