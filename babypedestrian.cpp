#include "babypedestrian.h"
#include "pedestrian.h"
#include <QTimer>
#include <QDebug>

BabyPedestrian::BabyPedestrian(QGraphicsItem * parent)
{

    QPixmap watermark(":/baby.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
    maxRange=550;
    distanceTravelled=0;
    speed = 6;
    qDebug() <<"baby created";
}

BabyPedestrian::~BabyPedestrian()
{

}

double BabyPedestrian::getMaxRange()
{
    return maxRange;
}

double BabyPedestrian::getDistanceCrawled()
{
    return distanceTravelled;
}

void BabyPedestrian::setMaxRange(double range)
{
    maxRange=range;
}

void BabyPedestrian::setDistanceCrawled(double dist)
{
    distanceTravelled= dist;
}


void BabyPedestrian::setCrawlSpeed(int speed)
{
    this->speed = speed;
}

int BabyPedestrian::getCrawlSpeed()
{
   return speed;
}
//overridding move



//change this from move to crawl
void BabyPedestrian::move()
{
    if(y()< maxRange ){
    setPos(x(), y()+speed);
    qDebug()<< "moving" ;
    }
    else{
        delete this;
    }
}
void BabyPedestrian::crawl()
{
    move();
}
