#ifndef METAK_H
#define METAK_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Metak: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Metak();
public slots:
    void move();
};

#endif // METAK_H
