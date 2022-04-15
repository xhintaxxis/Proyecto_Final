#ifndef CUERPO_H
#define CUERPO_H
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
class cuerpo: QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Fisica  * modefi;
    int vida=10;
    salud * energia;
public:
    cuerpo(float px_,float py_, float vx_, float vy_, int modelo_,QGraphicsScene * scene, QGraphicsItem* carr = 0);
    Fisica *getModefi() const;
    void proyectil();
    void posicionar();
    void keyPressEvent(QKeyEvent *event);
//public slots:
//    void VerColision();
};

#endif // CUERPO_H
