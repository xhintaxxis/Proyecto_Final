#ifndef ROCKREB_H
#define ROCKREB_H


#include<QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <fisica.h>
#include <QTimer>
#include <QDebug>

class rockreb:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rockreb(float px_,float py_, float vx_, float vy_, int modelo_, QGraphicsItem* carr = 0);
public slots:
    void posicionar1();
    void posicionar2();
private:
    QList<Fisica * > modelos;
};

#endif // ROCKREB_H
