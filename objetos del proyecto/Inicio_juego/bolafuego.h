#ifndef BOLAFUEGO_H
#define BOLAFUEGO_H

#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
class bolafuego:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bolafuego(QGraphicsItem* carr = 0);
    void posicionar();
private:
    Fisica * circular;
};

#endif // BOLAFUEGO_H
