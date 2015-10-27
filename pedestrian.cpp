#include "pedestrian.h"
#include <QPixmap>
#include <QTimer>
#include "qmath.h"

pedestrian::pedestrian(QGraphicsItem *parent)
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
}

double pedestrian::getMaxRange()
{
    return maxRange;
}

double pedestrian::getDistanceTravelled()
{
    return distanceTravelled;
}

void pedestrian::setMaxRange(double range)
{
    maxRange=range;
}

void pedestrian::setDistanceTravelled(double dist)
{
    distanceTravelled= dist;
}

void pedestrian::setSpeed(int speed1)
{
    speed =speed1;
}

int pedestrian::getSpeed()
{
    return speed;
}

void pedestrian::move()
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
