#include "athlete.h"
#include "pedestrian.h"
#include <QTimer>
athlete::athlete(QGraphicsItem * parent)
{

    QPixmap watermark(":/athlete.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
//    while(){
//       move();
//    }
    maxRange=550;
    distanceTravelled=0;
    speed = 6;
}

athlete::~athlete()
{

}

double athlete::getMaxRange()
{
    return maxRange;
}

double athlete::getDistanceTravelled()
{
    return distanceTravelled;
}

void athlete::setMaxRange(double range)
{
    maxRange=range;
}

void athlete::setDistanceTravelled(double dist)
{
    distanceTravelled= dist;
}


void athlete::setSpeed(int speed)
{
    this->speed = speed;
}

int athlete::getSpeed()
{
   return speed;
}
//overridding move
void athlete::move()
{
    if(y()< maxRange ){
    setPos(x(), y()+speed);
    }
    else{
        delete this;
    }
}


