/*
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
    speed = 5;
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

*/
