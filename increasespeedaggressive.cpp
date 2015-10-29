#include "increasespeedaggressive.h"

IncreaseSpeedAggressive::IncreaseSpeedAggressive()
{

}

void IncreaseSpeedAggressive:: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
       if(currentVehicle->currentSpeed < currentVehicle->HighAggressiveTopSpeed){
           doOperation(currentVehicle);
       }
    }

void IncreaseSpeedAggressive::doOperation(Vehicle * currentVehicle){
        currentVehicle->currentSpeed += 10;  //10KMPH
       // currentVehicle->image->frameGeometry()
        //currentVehic le->image->setGeometry(0,0, 270,270);
    }
