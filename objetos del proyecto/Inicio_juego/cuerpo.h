#ifndef CUERPO_H
#define CUERPO_H
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "rayo.h"
#include "fisica.h"
class cuerpo: QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Fisica  * modefi;

public:
    cuerpo(float px_,float py_, float vx_, float vy_, int modelo_, QGraphicsScene* scene, QGraphicsItem* carr = 0);
    void posicionar();
    void keyPressEvent(QKeyEvent *event);
    Fisica *getModefi() const;
    void proyectil();
};

#endif // CUERPO_H
