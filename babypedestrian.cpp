#include "babypedestrian.h"
#include "pedestrian.h"
#include <QTimer>
#include <QDebug>
#include <time.h>
#include <QCoreApplication>
#include <QTime>
using namespace std;

BabyPedestrian::BabyPedestrian(QGraphicsItem * parent)
{

    QPixmap watermark(":/baby.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
//    QTimer * move_timer = new QTimer(this);
//    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
//    move_timer->start(50);
//    maxRange=550;
    setPos(820,250);
    distanceTravelled=0;
    speed = 6;
    maxRange =550;
//   qDebug() <<"baby created";
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
  //  qDebug()<< "moving" ;
    }
    else{
        delete this;
    }
}
void BabyPedestrian::crawl(int x, int yPos)
{
    setPos(x,y()+20);
    int posOfXLights = x + 20;
    while(y() < getMaxRange()){
             setPos(posOfXLights,this->y()+20);
             delay();
             qApp->processEvents();
           //  qDebug()<<"moving";
           }
    delete this;
}

void BabyPedestrian::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(75);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


