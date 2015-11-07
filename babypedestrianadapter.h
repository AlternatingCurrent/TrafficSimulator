#ifndef BABYPEDESTRIANADAPTER_H
#define BABYPEDESTRIANADAPTER_H
#include "pedestrian.h"
#include "babypedestrian.h"
#include <QObject>

class BabyPedestrianAdapter: public pedestrian {
    Q_OBJECT
public:
    BabyPedestrianAdapter(BabyPedestrian *aBaby);
    ~BabyPedestrianAdapter();
    virtual double getMaxRange();
    virtual double getDistanceTravelled();
    virtual void setMaxRange(double range);
    virtual void setDistanceTravelled(double dist);
    virtual void setSpeed(int speed);
    virtual int  getSpeed();
    virtual void move2(int x, int yPos);
    virtual void delay();
public slots:
    virtual void move();
private:
    BabyPedestrian *theBaby;
};

#endif // BABYPEDESTRIANADAPTER_H
