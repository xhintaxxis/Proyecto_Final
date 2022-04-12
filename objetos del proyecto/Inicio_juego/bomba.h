#ifndef BOMBA_H
#define BOMBA_H

#include <QObject>
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "fisica.h"
class bomba:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bomba(float px_,float py_, float vx_, float vy_, int modelo_,QGraphicsItem* carr = 0);
    void posicionar();
private:
    Fisica * parabolico;
};

#endif // BOMBA_H
