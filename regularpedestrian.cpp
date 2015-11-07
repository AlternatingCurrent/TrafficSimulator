#include "regularpedestrian.h"
#include <QPixmap>
#include <QTimer>
#include "qmath.h"
#include <QDebug>
#include <QTimer>
#include <QPointF>
#include "qmath.h"
#include <QTransform>
#include <functional>
#include <iostream>
#include <time.h>
#include <QCoreApplication>
#include <QTime>
using namespace std;
RegularPedestrian::RegularPedestrian(QGraphicsItem *parent)
{
   // setPos(500,300);
    QPixmap watermark(":/person.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    maxRange=550;
    distanceTravelled=0;
    speed = 5;
 //connect a timer to move
//    QTimer * move_timer = new QTimer(this);
//    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
//    move_timer->start(50);

}

double RegularPedestrian::getMaxRange()
{
    return maxRange;
}

double RegularPedestrian::getDistanceTravelled()
{
    return distanceTravelled;
}

void RegularPedestrian::setMaxRange(double range)
{
    maxRange=range;
}

void RegularPedestrian::setDistanceTravelled(double dist)
{
    distanceTravelled= dist;
}

void RegularPedestrian::setSpeed(int speed1)
{
    speed =speed1;
}

int RegularPedestrian::getSpeed()
{
    return speed;
}

void RegularPedestrian::testMove()
{
//    int j=1;
//    while(j< 10){

//             setPos(500,y()+10);
//             qDebug()<<"moving" << y();
//             delay();
//             qApp->processEvents();
//             j++;
//           }

}

void RegularPedestrian::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(75);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void RegularPedestrian::move()
{
   int STEP_SIZE = 30;
   double theta = rotation(); // degrees
   double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
   double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
   if(y()< maxRange ){
   setPos(x(), y()+speed);
   qDebug()<< "Moving";
   }
   else{
       delete this;
   }

}





