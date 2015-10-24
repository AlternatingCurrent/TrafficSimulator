#include "vehiclestrategy.h"
class IncreaseSpeedMedium : public VehicleStrategy{

    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->MediumAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

    void doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 7;  //10KMPH
    }

};
