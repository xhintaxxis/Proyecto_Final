#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
class Enemigo_1:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemigo_1(float px_,float py_, float vx_, float vy_, int modelo_, QGraphicsItem* carr = 0);
    Fisica *getMovimiento() const;
    void posicionar();
private:
    Fisica * movimiento;
};

#endif // ENEMIGO_1_H
