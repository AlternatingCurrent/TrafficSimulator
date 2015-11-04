#include "decreasespeed.h"

DecreaseSpeed::DecreaseSpeed()
{

}
//May need to save original x & y value so these still work foir oncomming cars
void DecreaseSpeed :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
    for(int i=0; i<vehicles.size(); i++){

    //Decrease speed if the car in front is going slower than you and you start to collide areas
    if((currentVehicle->area->collidesWithItem(vehicles.at(i)->area)) &&(currentVehicle->pos().x() < vehicles.at(i)->pos().x())
       && (currentVehicle->pos().y() == vehicles.at(i)->pos().y()) &&
       (currentVehicle->currentSpeed > vehicles.at(i)->currentSpeed)){
           vehicleInFront = vehicles.at(i);
           doOperation(currentVehicle);
           break;
       }
    }
}

//Bug found, after overtaking because there ia an intersection the car behind matches the speed
void DecreaseSpeed :: doOperation(Vehicle * currentVehicle){

      // currentVehicle->currentSpeed = vehicleInFront->currentSpeed; //10KMPH
         currentVehicle->currentSpeed = currentVehicle->currentSpeed -10;
 }
