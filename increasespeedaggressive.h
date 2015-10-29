#ifndef INCREASESPEEDAGGRESSIVE_H
#define INCREASESPEEDAGGRESSIVE_H
#include "vehiclestrategy.h"
#include "vehicle.h"
#include <vector>

using namespace std;

class IncreaseSpeedAggressive:public VehicleStrategy
{
public:
    IncreaseSpeedAggressive();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
signals:

public slots:
};

#endif // INCREASESPEEDAGGRESSIVE_H
