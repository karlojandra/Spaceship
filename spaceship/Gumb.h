#ifndef GUMB_H
#define GUMB_H

#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>

class Gumb:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Gumb(QString name, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // GUMB_H

