#ifndef RAYO_H
#define RAYO_H

#include<QGraphicsItem>
#include<fisica.h>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <enemigo_1.h>
#include <QList>
#include <QDebug>
#include "jugador.h"
#include "enemigo_3.h"

class rayo:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rayo(float px_,float py_, float vx_, float vy_, int modelo_, QGraphicsItem* carr = 0);
    //void posicionar(float x,float y);
    bool getVacio() const;

public slots:
    void mover();
private:
    Fisica * uniforme;
    float pxi=0;
    float pyi=0;
    bool vacio=true;


};

#endif // RAYO_H
