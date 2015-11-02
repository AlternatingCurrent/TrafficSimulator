#ifndef ATHLETE_H
#define ATHLETE_H
#include "pedestrian.h"
#include <QObject>
class athlete: public pedestrian
{
    Q_OBJECT
public:
    athlete(QGraphicsItem * parent =0);
    ~athlete();
    virtual double getMaxRange();
    virtual double getDistanceTravelled();
    virtual void setMaxRange(double range);
    virtual void setDistanceTravelled(double dist);
    virtual void setSpeed(int speed);
    virtual int  getSpeed();
public slots:
    virtual void move();
private:
    double maxRange;
    double distanceTravelled;
    int speed; //to be changed for control via window
};

#endif // ATHLETE_H
