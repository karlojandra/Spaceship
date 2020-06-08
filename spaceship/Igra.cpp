#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QColor>
#include "Igra.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "Prepreke.h"
#include "Gumb.h"
#include <QBrush>
#include <QDebug>

QMediaPlayer * pof = new QMediaPlayer();
QTimer * timer = new QTimer();

Igra::Igra(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setScene(scene);
}
void Igra::start(){
    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/Slike/background.jpg")));

    igrac = new Igrac();
    igrac->setPos(350,415);
    igrac->setFlag(QGraphicsItem::ItemIsFocusable);
    igrac->setFocus();
    scene->addItem(igrac);

    points = new Points();
    scene->addItem(points);
    health = new Health();
    health->setPos(health->x(),health->y() + 25);
    scene->addItem(health);

    QObject::connect(timer,SIGNAL(timeout()),igrac,SLOT(spawn()));
    timer->start(1200);

    connect(points, SIGNAL(leba()), this, SLOT(spawn2()));

    connect(health, SIGNAL(dead()), this, SLOT(gameOver()));
}

void Igra::spawn2()
{
    qDebug() << "leba";
    timer->stop();
    timer->start(0);
}

void Igra::displayMainMenu(){

    setBackgroundBrush(QBrush(QImage(":/Slike/mainbackground.jpg")));

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("SpaceShip"));
    QFont titleFont("arial rounded mt bold",50);
    QColor titleColor("white");
    titleText->setDefaultTextColor(titleColor);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    QGraphicsTextItem* Company = new QGraphicsTextItem(QString("Jandra & Jelic"));
    QFont companyFont("arial rounded mt bold",25);
    QColor companyColor("white");
    Company->setDefaultTextColor(companyColor);
    Company->setFont(companyFont);
    int cxPos = 560;
    int cyPos = 560;
    Company->setPos(cxPos,cyPos);
    scene->addItem(Company);

    Gumb* playGumb = new Gumb(QString("Play"));
    int bxPos = this->width()/2 - playGumb->boundingRect().width()/2;
    int byPos = 275;
    playGumb->setPos(bxPos,byPos);
    connect(playGumb,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playGumb);

    Gumb* quitGumb = new Gumb(QString("Quit"));
    int qxPos = this->width()/2 - quitGumb->boundingRect().width()/2;
    int qyPos = 350;
    quitGumb->setPos(qxPos,qyPos);
    connect(quitGumb,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitGumb);

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Zvukovi/mainsong.mp2"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

}

void Igra::gameOver(){

    QString message;
    pof->setMedia(QUrl("qrc:/Zvukovi/Mario.mp2"));
    pof->play();
    displayGameOverWindow(message);

}

void Igra::displayGameOverWindow(QString textToDisplay){

    scene->clear();

    setBackgroundBrush(QBrush(QImage(":/Slike/mainbackground.jpg")));

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("You Lost!!!"));
    QFont titleFont("arial rounded mt bold",50);
    QColor titleColor("white");
    titleText->setDefaultTextColor(titleColor);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Gumb* playAgain = new Gumb(QString("Play Again"));
    int pxPos = this->width()/2 - playAgain->boundingRect().width()/2;
    int pyPos = 275;
    playAgain->setPos(pxPos, pyPos);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));


    Gumb* quit = new Gumb(QString("Quit"));
    int qxPos = this->width()/2 - quit->boundingRect().width()/2;
    int qyPos = 350;
    quit->setPos(qxPos, qyPos);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(460,225);
    scene->addItem(overText);
}

