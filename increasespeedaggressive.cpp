#include "vehiclestrategy.h"
#include "vehicle.h"

class IncreaseSpeedAggressive:public VehicleStrategy{


    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->HighAggressiveTopSpeed){
           doOperation(currentVehicle);
       }
    }

    void doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 10;  //10KMPH
    }

};
