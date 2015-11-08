#include "subject.h"

#include <iostream>

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
    notifyAllVehicles();
}

void Subject::attach(Vehicle * aVehicle){
   vehicles.push_back(aVehicle);
}

void Subject::notifyAllVehicles(){
  for(int i =0; i< vehicles.size();i++){
    //  vehicles.at(i)->update(vehicles);   //Same as update()
  }
}
