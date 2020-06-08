#ifndef PREPREKE_H
#define PREPREKE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Prepreke: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Prepreke();
public slots:
    void move();
};


#endif // PREPREKE_H
