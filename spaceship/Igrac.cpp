#include "Igrac.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Metak.h"
#include "Prepreke.h"
#include "Igra.h"

extern Igra * igra;

Igrac::Igrac(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/Zvukovi/quack.wav"));

    setPixmap(QPixmap(":/Slike/ship.png"));
}

void Igrac::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-15,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos(). x() + 100 < 800)
        setPos(x()+15,y());
    }
    else if (event->key() == Qt::Key_Space){
        Metak * metak = new Metak();
        metak->setPos(x()+47,y()-30);
        scene()->addItem(metak);
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }

    }

}

void Igrac::spawn(){
    Prepreke * prepreke = new Prepreke();
    scene()->addItem(prepreke);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Prepreke)){
            igra->health->decrease();

            scene()->removeItem(colliding_items[i]);

            delete colliding_items[i];
            return;

        }

    }
}
