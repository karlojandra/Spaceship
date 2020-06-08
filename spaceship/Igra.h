#ifndef IGRA_H
#define IGRA_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Igrac.h"
#include "Points.h"
#include "Health.h"

class Igra: public QGraphicsView{
    Q_OBJECT
public:
    Igra(QWidget * parent=NULL);

    void displayMainMenu();
    void displayGameOverWindow(QString textToDisplay);

    QGraphicsScene * scene;
    Igrac * igrac;
    Points * points;
    Health * health;

public slots:
    void start();
    void gameOver();
    void spawn2();
};

#endif // IGRA_H
