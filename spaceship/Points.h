#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>

class Points: public QGraphicsTextItem{
    Q_OBJECT
public:
    Points(QGraphicsItem * parent=0);
    void increase();
    int getPoints();
    int points;
signals:
    void leba();
};

#endif // POINTS_H
