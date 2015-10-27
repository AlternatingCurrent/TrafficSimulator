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
    maxRange=550;
    distanceTravelled=0;

}

athlete::~athlete()
{

}

void athlete::setSpeed(int speed)
{
    pedestrian::setSpeed(speed);
}

int athlete::getSpeed()
{
   return pedestrian::getSpeed();
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


