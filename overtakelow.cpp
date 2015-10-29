#include "overtakelow.h"

OvertakeLow::OvertakeLow()
{

}

void OvertakeLow :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->LowAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

void OvertakeLow :: doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 5;  //10KMPH
 }
