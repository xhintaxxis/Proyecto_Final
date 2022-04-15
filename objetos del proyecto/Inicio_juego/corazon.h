#ifndef CORAZON_H
#define CORAZON_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>

class corazon:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    corazon(QGraphicsItem *carr=0);
};

#endif // CORAZON_H
