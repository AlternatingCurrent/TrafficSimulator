#ifndef DECREASESPEED_H
#define DECREASESPEED_H
#include "vehiclestrategy.h"
#include "vehicle.h"


class DecreaseSpeed:public VehicleStrategy
{
public:
    DecreaseSpeed();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
private:
    Vehicle * vehicleInFront;

signals:

public slots:
};

#endif // DECREASESPEED_H
