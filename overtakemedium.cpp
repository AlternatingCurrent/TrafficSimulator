#include "overtakemedium.h"

OverTakeMedium::OverTakeMedium()
{

}

void OverTakeMedium :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->LowAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

void OverTakeMedium :: doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 5;  //10KMPH
 }
