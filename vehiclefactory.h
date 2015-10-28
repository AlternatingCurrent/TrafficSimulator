#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "vehicle.h"
#include "subject.h"
class VehicleFactory
{
public:
    //depending on what we end up on in relation to vehicles and what they can do this will be changed again
    VehicleFactory();
    Vehicle *createVehicle(QString type);
    Vehicle *createRandomVehicle(); //random aggressivness
    Vehicle *createVehicle(QString type, QString Aggressiveness, QString startingSpeed);
    ~VehicleFactory();
private:
    Subject * asubject;
};

#endif // VEHICLEFACTORY_H
