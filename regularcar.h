#ifndef REGULARCAR_H
#define REGULARCAR_H
#include "vehicle.h"
#include "subject.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <vector>

using namespace std;

class RegularCar : public Vehicle
{
    Q_OBJECT
public:
    RegularCar(Subject *aVehicle,int width, int height, double aggression, QGraphicsItem * parent = 0);
    //Dont need update() here as it is virtual() just provide implementation
    void update(vector<Vehicle*> vehicles);
    void setUp();
    //QGraphicsRectItem * area;
//signals:

//public slots:
};

#endif // REGULARCAR_H
