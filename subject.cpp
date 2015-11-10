#include "subject.h"

#include <iostream>
#include "vehicle.h"
using namespace std;

Subject::Subject()
{
 //vehicles = new List();
}

int Subject::getState(){
   return state;
}

void Subject::setState(int state){
    this->state = state;
    //Case for the state mayve
    //1 to begin
    //2 pedestrian crossing
    //3 traffic lights


    if(state==1){
     notifyAllVehicles(1);
    }
    else{

       notifyAllVehicles(0);
    }
}

void Subject::attach(Vehicle * aVehicle){
   vehicles.push_back(aVehicle);
}

void Subject::notifyAllVehicles(int on){
if(on==1){
  for(int i =0; i< vehicles.size();i++){
   vehicles.at(i)->updateTrafficLightsSignal(true);  //Same as update()
  }}
else{
    for(int i =0; i< vehicles.size();i++){
     vehicles.at(i)->updateTrafficLightsSignal(false);  //Same as update()
    }}
}




void Subject::traffic_light_notify_all_vehicles(bool isOn)
{

 //change this when colin updates his vehicle and modify it to let vehicles knwo traffic lights are on
}
