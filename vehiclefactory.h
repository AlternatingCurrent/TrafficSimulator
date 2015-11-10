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
    Vehicle *createVehicle(QString type, int Aggressiveness, int xPosition, int yPosition, Subject *subject);
    ~VehicleFactory();
private:
    Subject * asubject;
    Vehicle * setup(Vehicle * vehicle, QString type);
};

#endif // VEHICLEFACTORY_H
