#include "subject.h"

#include <iostream>

using namespace std;

Subject::Subject()
{
 //vehicles = new List();
}

Subject::getState(){
   return state;
}

void Subject::setState(int state){
    this->state = state;
    notifyAllVehicles();
}

void Subject::attach(Vehicle * aVehicle){
   vehicles.push_back(aVehicle);
}

void Subject::notifyAllVehicles(){
  for(int i =0; i< vehicles.size();i++){
      vehicles.at(i)->update();   //Same as update()
  }
}
