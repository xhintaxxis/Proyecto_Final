#include "salud.h"

salud::salud(int vida_, QGraphicsItem *parent)
{
    vida_ = vida;
    setPlainText(QString::number(vida)); // health
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setPos(40,10);
}

void salud::dano(int damage)
{
    vida=vida-damage;
    setPlainText(QString::number(vida));
}

int salud::getVida() const
{
    return vida;
}
