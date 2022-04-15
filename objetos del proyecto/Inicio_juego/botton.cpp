#include "botton.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
botton::botton(QString name, QGraphicsItem * parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // dibujar el texto

    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 -text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

//    setPlainText(QString::number(name)); // health
//    setDefaultTextColor(Qt::red);
//    setFont(QFont("times",16));
//    setPos(40,10);
    setAcceptHoverEvents(true);
}

void botton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit click();
}

void botton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void botton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
