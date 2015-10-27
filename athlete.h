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
    void setSpeed(int speed);
    int  getSpeed();
public slots:
    void move();
private:
    double maxRange;
    double distanceTravelled;
    int speed; //to be changed for control via window
};

#endif // ATHLETE_H
