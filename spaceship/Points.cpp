#include "Points.h"
#include <QFont>
#include "Igra.h"

extern Igra * igra;

Points::Points(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    points = 0;

    setPlainText(QString("Points: ") + QString::number(points));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));

}

void Points::increase(){
    points++;
    setPlainText(QString("Points: ")+ QString::number(points));

    if(points == 100){
        emit leba();
    }
}

int Points::getPoints(){
    return points;
}
