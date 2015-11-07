#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
class pedestrian: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    virtual double getMaxRange() = 0;
    virtual double getDistanceTravelled() = 0;
    virtual void setMaxRange(double range) = 0;
    virtual void setDistanceTravelled(double dist) = 0;
    virtual void setSpeed(int speed1) = 0;
    virtual int  getSpeed() = 0;
    virtual void move2(int x, int y) = 0;
    virtual void delay() =0;
public slots:
   virtual void move() = 0;

private:
    double maxRange;
    double distanceTravelled;
    int speed; // this is just for now, this will have to be able to be set in the menu by the user

};
#endif


