#ifndef VEHICLESTRATEGY
#define VEHICLESTRATEGY
//#include "vehicle.h"

#include <vector>
using namespace std;

class Vehicle;
class VehicleStrategy{

public:
VehicleStrategy(){}
virtual ~VehicleStrategy(){}
virtual void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle) =0;
virtual void doOperation(Vehicle * aVehicle) = 0;
int newCoOrdinateBasedOnSpeed;
};
#endif // VEHICLESTRATEGY

