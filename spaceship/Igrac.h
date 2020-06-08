#ifndef IGRAC_H
#define IGRAC_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>


class Igrac:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Igrac(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
};

#endif // IGRAC_H
