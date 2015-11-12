#include "increasespeedmedium.h"

IncreaseSpeedMedium::IncreaseSpeedMedium()
{

}

void IncreaseSpeedMedium :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){

    bool collidesWithItemInFront = false;

    for(int i =0; i< vehicles.size(); i++){
        if(currentVehicle->area->collidesWithItem(vehicles.at(i)->area) && (currentVehicle->pos().y() == vehicles.at(i)->pos().y())
           && (currentVehicle->pos() !=vehicles.at(i)->pos())  &&(vehicles.at(i)->pos().x() > currentVehicle->pos().x())){
            collidesWithItemInFront = true;
        }

    }

       if((currentVehicle->currentSpeed <= currentVehicle->MediumAggressiveTopSpeed) && (currentVehicle->currentSpeed <=  currentVehicle->speedLimit)
           && collidesWithItemInFront == false){
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

void IncreaseSpeedMedium :: doOperation(Vehicle * currentVehicle){
   // currentVehicle->setPos(newCoOrdinateBasedOnSpeed, (currentVehicle->pos().y()));
    emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,newCoOrdinateBasedOnSpeed,currentVehicle->pos().y());
}
