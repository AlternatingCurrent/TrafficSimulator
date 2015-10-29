#ifndef OVERTAKEMEDIUM_H
#define OVERTAKEMEDIUM_H
#include "vehiclestrategy.h"
#include "vehicle.h"


class OverTakeMedium:public VehicleStrategy
{
public:
    OverTakeMedium();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
signals:

public slots:
};

#endif // OVERTAKEMEDIUM_H
