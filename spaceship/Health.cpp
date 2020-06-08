#include "Health.h"
#include "Igra.h"
#include <QFont>
#include <QTimer>
#include <QMediaPlayer>

QTimer * timer4 = new QTimer();
QMediaPlayer * oof = new QMediaPlayer();

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ")+ QString::number(health));

    oof->setMedia(QUrl("qrc:/Zvukovi/OOF.mp2"));
    oof->play();

    if ( health == 0 ){
        connect(timer4,SIGNAL(timeout()),this,SLOT(baba()));
        timer4->start(200);
    }
}

void Health::baba(){
    emit dead();
    timer4->stop();
}

int Health::getHealth(){
    return health;
}
