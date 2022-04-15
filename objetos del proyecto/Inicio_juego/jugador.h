#ifndef JUGADOR_H
#define JUGADOR_H
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "rayo.h"
#include "fisica.h"
#include "QList"
#include <QDebug>
#include "salud.h"
#include "corazon.h"
#include <QKeyEvent>
#include <QGraphicsScene>
class jugador:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jugador(QGraphicsScene* scene,QGraphicsItem * parent=0);
    void garbage();
private:
    Fisica  * modefi;
    int vida=10;
    salud * energia;
    corazon * heart;
};

#endif // JUGADOR_H
