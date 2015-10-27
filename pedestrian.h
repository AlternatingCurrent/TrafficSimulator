#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class pedestrian: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    pedestrian(QGraphicsItem * parent =0);
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double range);
    void setDistanceTravelled(double dist);
    void setSpeed(int speed1);
    int  getSpeed();
public slots:
   virtual void move();

private:
    double maxRange;
    double distanceTravelled;
    int speed = 5; // this is just for now, this will have to be able to be set in the menu by the user

};
#endif


