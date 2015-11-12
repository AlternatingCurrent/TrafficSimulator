#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "vehicle.h"
#include "subject.h"
#include <QGraphicsScene>

class VehicleFactory
{
public:
    //depending on what we end up on in relation to vehicles and what they can do this will be changed again
    VehicleFactory();
    Vehicle *createVehicle(QString type);
    Vehicle *createRandomVehicle(); //random aggressivness
    Vehicle *createVehicle(QString type, string aggressiveness, int xPosition, int yPosition, Subject *subject, QGraphicsScene *scene, string direction);
    ~VehicleFactory();
private:
    Subject * asubject;
    Vehicle * setup(Vehicle * vehicle, QString type, int x, int y);
    int aggressive;
};

#endif // VEHICLEFACTORY_H
