#include "increasespeedmedium.h"

IncreaseSpeedMedium::IncreaseSpeedMedium()
{

}

void IncreaseSpeedMedium :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->LowAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

void IncreaseSpeedMedium :: doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 5;  //10KMPH
 }
