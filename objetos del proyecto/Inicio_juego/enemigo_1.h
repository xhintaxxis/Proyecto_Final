#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include "bomba.h"
#include "rayoe.h"
class Enemigo_1:QObject,
        public QGraphicsPixmapItem
        //,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemigo_1(float px_, float py_, float vx_, float vy_, int modelo_,int douP, QGraphicsItem *car);
    Fisica *getMovimiento() const;
    void posicionar();
public slots:
    void mover();
    void proyectil();
    void douProyectil();
private:
    Fisica * movimiento;
    bool Cambio = false;
    double amplitud = 0;
};

#endif // ENEMIGO_1_H
