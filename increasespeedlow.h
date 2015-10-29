#ifndef INCREASESPEEDLOW_H
#define INCREASESPEEDLOW_H

#include "vehiclestrategy.h"
#include "vehicle.h"

class IncreaseSpeedLow:public VehicleStrategy
{
public:
    IncreaseSpeedLow();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
signals:

public slots:
};

#endif // INCREASESPEEDLOW_H
