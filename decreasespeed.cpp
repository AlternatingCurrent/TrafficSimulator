#include "decreasespeed.h"

DecreaseSpeed::DecreaseSpeed()
{

}

void DecreaseSpeed :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->LowAggressiveTopSpeed && currentVehicle->currentSpeed < currentVehicle->speedLimit){
           doOperation(currentVehicle);
       }
    }

void DecreaseSpeed :: doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 5;  //10KMPH
 }
