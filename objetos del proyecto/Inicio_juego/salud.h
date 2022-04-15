#ifndef SALUD_H
#define SALUD_H
#include <QFont>
#include <QGraphicsTextItem>

class salud:
        public QGraphicsTextItem
{
public:
    salud(int vida_, QGraphicsItem * parent = 0);
    void dano(int damage);
    int getVida() const;

private:
    int vida=20;

};

#endif // SALUD_H
