#ifndef RAYOE_H
#define RAYOE_H

#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "fisica.h"
#include <QTimer>
#include <time.h>
#include <QDebug>

class rayoE:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rayoE(float px_,float py_, float vx_, float vy_, int modelo_, QGraphicsItem* carr = 0);
public slots:
    void posicionar();
private:
    Fisica * Uniforme;
};

#endif // RAYOE_H
