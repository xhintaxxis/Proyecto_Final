#ifndef JEFE2_H
#define JEFE2_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include <math.h>
#include <rayoe.h>
#include <bomba.h>
#include <rayo.h>
class jefe2:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jefe2(QGraphicsItem* carr = 0);
    void fisica();
    int vida=70;
public slots:
    void posicionar();
    void proyectiles();
private:
    float theta=0.1;
    float ampx=100;
    float ampy=200;
    float cx=700;
    float cy=170;
    float px;
    float py;


};

#endif // JEFE2_H
