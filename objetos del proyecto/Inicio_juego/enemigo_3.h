#ifndef ENEMIGO_3_H
#define ENEMIGO_3_H
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "fisica.h"
#include "bomba.h"
#include <QTimer>
#include <time.h>
#include <QDebug>
#include "rayo.h"
class enemigo_3:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Fisica * oscilacion;
    Fisica * parabolico;
    int vida=10;
public:
    enemigo_3(float px_,float py_,float Ampli_, QGraphicsItem* carr = 0);
    Fisica *getOscilacion() const;
    void parabolic();
    int cambio=0;
public slots:
    void posicionar();
};

#endif // ENEMIGO_3_H
