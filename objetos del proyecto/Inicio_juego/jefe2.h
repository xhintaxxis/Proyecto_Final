#ifndef JEFE2_H
#define JEFE2_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
class jefe2:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jefe2();
};

#endif // JEFE2_H
