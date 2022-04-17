#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
class Obstaculo:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo(float px_, float py_, float vx_, float vy_, int modelo_, QGraphicsItem *car=0);
private:
    Fisica  * unifome;
public slots:
    void posicionar();
};

#endif // OBSTACULO_H
