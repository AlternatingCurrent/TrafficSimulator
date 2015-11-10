#include "overtakelow.h"

//Will never try and overtake, maybe in a future iteration they can overtake bicycles

OvertakeLow::OvertakeLow()
{

}

void OvertakeLow :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){

    }

void OvertakeLow :: doOperation(Vehicle * currentVehicle){

    //Interceptor code here, need to log the overtaking
    //First create the context object with the currect speed
    currentVehicle->cObj = ContextObject(currentVehicle->currentSpeed);
    //Now pass the context object to the dispatcher to be recorded
    currentVehicle->dis.callback(&currentVehicle->cObj);
 }
