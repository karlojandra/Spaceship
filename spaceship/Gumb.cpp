#include "Gumb.h"
#include <QGraphicsTextItem>
#include <QBrush>


Gumb::Gumb(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void Gumb::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Gumb::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::magenta);
    setBrush(brush);
}

void Gumb::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);
}

