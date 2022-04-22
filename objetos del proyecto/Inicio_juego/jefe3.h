#ifndef JEFE3_H
#define JEFE3_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include "rayo.h"
#include "rayoe.h"
#include "bolafuego.h"
#include "rockreb.h"
#include <QDebug>
class jefe3:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jefe3(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsScene *scene, QGraphicsItem *carr=0);
    QList <rayoE *> bala;
    QList <QTimer *> timers;
    QList<bolafuego*> ball;
    QList<rockreb*> roca;
    int vida=100;
private:
    Fisica * uniforme;
    int cambio=1;
    int corrector=1;
    int balacambio=1;
public slots:
    void posicionar();
    void proyectiles();
    void repetir();
};

#endif // JEFE3_H
