#ifndef BOLAFUEGO_H
#define BOLAFUEGO_H

#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include <QDebug>
class bolafuego:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bolafuego(QGraphicsItem* carr = 0);
     void movimiento();
public slots:
    void posicionar();
private:
    Fisica * circular;
private:
    float theta=0.1;
    float ampx=100;
    float ampy=200;
    float ampxdt=1;
    float cx=410;
    float cy=170;
    float px;
    float py;
};

#endif // BOLAFUEGO_H
