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
#include <enemigo_2.h>
#include <obstaculo.h>
class cuerpo: QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Fisica  * modefi;


public:
    salud * energia;
    int vida=10;
    cuerpo(float px_,float py_, float vx_, float vy_, int modelo_,QGraphicsScene * scene, QGraphicsItem* carr = 0);
    Fisica *getModefi() const;
    void proyectil();
    void posicionar();
    void keyPressEvent(QKeyEvent *event);
    void menu();
    QList<rayo * > bala;
public slots:
   void VerColision();
signals:
   void lose();
};

#endif // CUERPO_H
