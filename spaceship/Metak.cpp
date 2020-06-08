#include "Metak.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Prepreke.h"
#include "Igra.h"

extern Igra * igra;

Metak::Metak(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/Slike/bullet.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(50);
}

void Metak::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Prepreke)){
            igra->points->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }

    }

    setPos(x(),y()-20);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
