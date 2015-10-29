#ifndef INCREASESPEEDMEDIUM_H
#define INCREASESPEEDMEDIUM_H
#include "vehiclestrategy.h"
#include "vehicle.h"


class IncreaseSpeedMedium:public VehicleStrategy
{
public:
    IncreaseSpeedMedium();
    void decision(vector <Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
signals:

public slots:
};

#endif // INCREASESPEEDMEDIUM_H
