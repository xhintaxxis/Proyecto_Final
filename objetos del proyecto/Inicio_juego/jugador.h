#ifndef JUGADOR_H
#define JUGADOR_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "fisica.h"
#include <QDebug>
class jugador:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    jugador(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    Fisica *getUniforme() const;

private:
    Fisica * uniforme;
};

#endif // JUGADOR_H
