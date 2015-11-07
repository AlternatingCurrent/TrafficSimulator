#ifndef REGULARPEDESTRIAN_H
#define REGULARPEDESTRIAN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "pedestrian.h"

class RegularPedestrian:public pedestrian{

public:
    RegularPedestrian(QGraphicsItem * parent =0);
    virtual double getMaxRange();
    virtual double getDistanceTravelled();
    virtual void setMaxRange(double range);
    virtual void setDistanceTravelled(double dist);
    virtual void setSpeed(int speed1);
    virtual int  getSpeed();
    virtual void move2(int x, int yPos);
    virtual void delay();
public slots:
   virtual void move();

private:
    double maxRange;
    double distanceTravelled;
    int speed; // this is just for now, this will have to be able to be set in the menu by the user

};

#endif // REGULARPEDESTRIAN_H
