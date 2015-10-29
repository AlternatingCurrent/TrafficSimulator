#ifndef STRATEGYCONTEXT_H
#define STRATEGYCONTEXT_H

#include "vehiclestrategy.h"
//#include "vehicle.h"
#include <vector>
class Vehicle;
using namespace std;

class StrategyContext
{
public:
    StrategyContext(VehicleStrategy *strategy);
    ~StrategyContext();
    VehicleStrategy * strategy;
    void executeStrategyDecision(vector<Vehicle*> vehicles, Vehicle * currentVehicle);
    void executeStrategyOperation(Vehicle * currentVehicle);

signals:

public slots:
};

#endif // STRATEGYCONTEXT_H
