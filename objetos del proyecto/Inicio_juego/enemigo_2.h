#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include "rayo.h"

class enemigo_2:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemigo_2(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *car=0);
public slots:
    void posicionar();
private:
    Fisica * uniforme;
    int vida=10;
};


#endif // ENEMIGO_2_H
