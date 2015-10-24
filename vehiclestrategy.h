#ifndef VEHICLESTRATEGY
#define VEHICLESTRATEGY
#include "Vehicle.h"
#include <vector>

using namespace std;
class VehicleStrategy{

protected:
VehicleStrategy(){}
virtual ~VehicleStrategy(){}
virtual void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle) =0;
virtual void doOperation(Vehicle * aVehicle) =0;

};
#endif // VEHICLESTRATEGY

