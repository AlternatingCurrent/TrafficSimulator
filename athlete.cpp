#include "athlete.h"
#include "pedestrian.h"
#include <QTimer>
#include <time.h>
#include <QCoreApplication>
#include <QTime>
using namespace std;
athlete::athlete(QGraphicsItem * parent)
{

    QPixmap watermark(":/athlete.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
//    QTimer * move_timer = new QTimer(this);
//    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
//    move_timer->start(50);
    maxRange=550;
    distanceTravelled=0;
    speed = 6;
    setPos(820,250+getSpeed());
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

void athlete::move2(int x, int yPos)
{
    setPos(x,y()+20);
    int posOfXLights = x + 20;
    while(y() < getMaxRange()){
             setPos(posOfXLights,this->y()+20);
             delay();
             qApp->processEvents();
           }
    delete this;
}

void athlete::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(75);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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


