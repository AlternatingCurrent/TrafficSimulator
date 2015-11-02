#include "regularpedestrian.h"
#include <QPixmap>
#include <QTimer>
#include "qmath.h"

RegularPedestrian::RegularPedestrian(QGraphicsItem *parent)
{
    QPixmap watermark(":/person.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);

    //connect a timer to move
    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
    maxRange=550;
    distanceTravelled=0;
    speed = 5;
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

void RegularPedestrian::move()
{
   int STEP_SIZE = 30;
   double theta = rotation(); // degrees
   double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
   double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));
   if(y()< maxRange ){
   setPos(x(), y()+speed);
   }
   else{
       delete this;
   }

}
