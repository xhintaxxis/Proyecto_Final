#ifndef ENEMIGO_3_H
#define ENEMIGO_3_H
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "fisica.h"

class enemigo_3:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Fisica * oscilacion;
public:
    enemigo_3(float px_,float py_,float Ampli_, QGraphicsItem* carr = 0);
    Fisica *getOscilacion() const;
    void posicionar();
};

#endif // ENEMIGO_3_H
