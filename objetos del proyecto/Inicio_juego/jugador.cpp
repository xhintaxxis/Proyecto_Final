#include "jugador.h"
#include "QKeyEvent"

jugador::jugador(QGraphicsScene *scene, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    modefi = new Fisica(0,250,0,0,0);
    setPixmap(QPixmap(":/images/New Piskel.png"));
    setPos(90,90);
    heart = new corazon();
    scene->addItem(heart);

    //energia = new salud(10);
//    scene()->addItem(energia);
//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(VerColision()));
    //    timer->start(30);
}

void jugador::garbage()
{
    free(heart);

}

