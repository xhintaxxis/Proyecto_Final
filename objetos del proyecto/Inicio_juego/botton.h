#ifndef BOTTON_H
#define BOTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class botton: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
    botton(QString name, QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
signals:
    void click();
private:
    QGraphicsTextItem *text ;
};

#endif // BOTTON_H
