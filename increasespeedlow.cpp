#include "increasespeedlow.h"
#include <iostream>
using namespace std;
IncreaseSpeedLow::IncreaseSpeedLow()
{

}


void IncreaseSpeedLow :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if((currentVehicle->currentSpeed <= currentVehicle->LowAggressiveTopSpeed) && (currentVehicle->currentSpeed <= currentVehicle->speedLimit)){
          newCoOrdinateBasedOnSpeed = (currentVehicle->pos().x()) + ((currentVehicle->currentSpeed += 10) /10);
          if(currentVehicle->direction == "west"){
              newCoOrdinateBasedOnSpeed = (currentVehicle->pos().x()) - ((currentVehicle->currentSpeed += 10) /10);
          }
          doOperation(currentVehicle);
       }else{
         //If they reach thier top speed then increase proportionate to the top speed
         newCoOrdinateBasedOnSpeed = (currentVehicle->pos().x()) + ((currentVehicle->currentSpeed) /10);
         if(currentVehicle->direction == "west"){
             newCoOrdinateBasedOnSpeed = (currentVehicle->pos().x()) - ((currentVehicle->currentSpeed += 10) /10);
         }
         doOperation(currentVehicle);
     }
    }

void IncreaseSpeedLow :: doOperation(Vehicle * currentVehicle){
   // currentVehicle->setPos(newCoOrdinateBasedOnSpeed, (currentVehicle->pos().y()));
    emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,newCoOrdinateBasedOnSpeed,currentVehicle->pos().y());
}
