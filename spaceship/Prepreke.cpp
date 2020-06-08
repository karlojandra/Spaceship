#include "Prepreke.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Igra.h"

extern Igra * igra;

Prepreke::Prepreke(): QObject(), QGraphicsPixmapItem()
{
    int random_broj = rand() % 700;
    setPos(random_broj,0);

    setPixmap(QPixmap(":/Slike/asteroid.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(40);
}

void Prepreke::move()
{
    setPos(x(),y()+5);
    if (pos().y() > 600){
        igra->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
