 #include "increasespeedaggressive.h"
#include <iostream>

using namespace std;

IncreaseSpeedAggressive::IncreaseSpeedAggressive()
{

}

//Might make some of the conditions in the if statements part of the vehicle class to minimise if's as the check is duplicated elsewhere
//Aswell as making the code easier to read
void IncreaseSpeedAggressive:: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       bool collidesWithItemInFront = false;


       for(unsigned i =0; i< vehicles.size(); i++){
           //if thw vehicle is colliding with the vehicle in front and they are on the same road && it is not the current vehicle
           if(currentVehicle->area->collidesWithItem(vehicles.at(i)->area) && (currentVehicle->pos().y() == vehicles.at(i)->pos().y()) &&(vehicles.at(i)->pos().x() > currentVehicle->pos().x())
              && (currentVehicle->pos() !=vehicles.at(i)->pos())){
               collidesWithItemInFront = true;
           }

       }
        //Add a 10KMPH onto the x axis for every time they do not exceed their speed limit
       if(currentVehicle->currentSpeed <= currentVehicle->HighAggressiveTopSpeed && collidesWithItemInFront == false){
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

void IncreaseSpeedAggressive::doOperation(Vehicle * currentVehicle){
      // currentVehicle->setPos(newCoOrdinateBasedOnSpeed, (currentVehicle->pos().y()));
       emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,newCoOrdinateBasedOnSpeed,currentVehicle->pos().y());
    }
