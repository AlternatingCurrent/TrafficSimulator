#include "overtakemedium.h"

OverTakeMedium::OverTakeMedium()
{

}

void OverTakeMedium :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
    bool isColliding = false;

    for(int i=0; i<vehicles.size(); i++){

    //make sure we are not looking at the current vehicle inside in the vector
    if(currentVehicle->pos() !=vehicles.at(i)->pos() ){

        //change 450
        //Will only be able to overtake low aggressive drivers
       if((currentVehicle->area->collidesWithItem((vehicles.at(i)->area))) &&(currentVehicle->pos().x() < vehicles.at(i)->pos().x()) &&
       (currentVehicle->pos().y() ==   450)  && (vehicles.at(i)->aggression == currentVehicle->Low)){
           doOperation(currentVehicle);
       }

    //See if vehicle is colliding with any vehicle on the left hand side of the road
    if( currentVehicle->area->collidesWithItem(vehicles.at(i)->area) && (vehicles.at(i)->pos().y() == 450) ){
           isColliding = true;
    }
    }
    }
    //We can move back in if we are no longer colliding with any vehicles
    if((currentVehicle->isOvertaking == true) && (isColliding == false) ){
         currentVehicle->setPos((currentVehicle->pos().x()), (currentVehicle->pos().y()-50));
         currentVehicle->isOvertaking = false;
    }
  }

void OverTakeMedium :: doOperation(Vehicle * currentVehicle){
        currentVehicle->setPos((currentVehicle->pos().x()), (currentVehicle->pos().y()+50));
        currentVehicle->isOvertaking = true;
 }
