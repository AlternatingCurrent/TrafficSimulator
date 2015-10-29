#ifndef OVERTAKELOW_H
#define OVERTAKELOW_H
#include "vehiclestrategy.h"
#include "vehicle.h"


class OvertakeLow:public VehicleStrategy
{
public:
    OvertakeLow();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
signals:

public slots:
};

#endif // OVERTAKELOW_H
