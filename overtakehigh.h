#ifndef OVERTAKEHIGH_H
#define OVERTAKEHIGH_H
#include "vehiclestrategy.h"
#include "vehicle.h"


class OvertakeHigh:public VehicleStrategy
{
public:
    OvertakeHigh();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);

signals:

public slots:
};

#endif // OVERTAKEHIGH_H
