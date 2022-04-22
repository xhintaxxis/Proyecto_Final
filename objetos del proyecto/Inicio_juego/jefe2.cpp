#include "jefe2.h"

jefe2::jefe2(QGraphicsItem* carr)
{
    setPixmap(QPixmap(":/images/jefe2.png"));
    this->setPos(cx+ampx,cy);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(posicionar()));
    timer->start(40);
    QTimer * timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(proyectiles()));
    timer2->start(270);
}

void jefe2::fisica()
{
    px=ampx*cos(theta)+cx;
    py=ampy*sin(theta)+cy;
    theta+=0.1;
}

void jefe2::posicionar()
{
    fisica();
    setPos(px,py);
    QList<QGraphicsItem *> colisionBala =collidingItems();
    for(int i =0;i<colisionBala.size();i++){
        if(typeid (*colisionBala.at(i))==typeid (rayo)){
            scene()->removeItem(colisionBala.at(i));
            delete colisionBala.at(i);
            vida--;
        }
    }

}

void jefe2::proyectiles()
{
    static int cont = 0;
    bala.append(new rayoE(px,py+37,-10,0,0));
    scene()->addItem(bala.at(bala.size()-1));
//    rayoE * bala = new rayoE(px,py+87,-8,0,0,0);
//    scene()->addItem(bala);
    if(cont==3){
//        bomba * bomb = new bomba(px,py+37,-10,-2,1);
//        scene()->addItem(bomb);
        bomb.append(new bomba(px,py+37,-7,2,1));
        scene()->addItem(bomb.at(bomb.size()-1));
        cont=0;
    }
    else{
        cont++;
    }

}
