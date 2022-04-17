#ifndef JEFE1_H
#define JEFE1_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include "rayo.h"
#include "rayoe.h"
class jefe1:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jefe1(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *carr=0);
    int vida=1;
public slots:
    void posicionar();
    void proyectil();
private:
    Fisica * uniforme;
//    rayoE * rayo1;
//    rayoE * rayo2;
//    rayoE * rayo3;
    QTimer * timer2;
};

#endif // JEFE1_H
