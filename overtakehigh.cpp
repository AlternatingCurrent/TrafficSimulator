#include "overtakehigh.h"

OvertakeHigh::OvertakeHigh()
{

}

void OvertakeHigh :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->LowAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

void OvertakeHigh :: doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 5;  //10KMPH
 }
