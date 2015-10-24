#include "vehicle.h"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(int width, int height, int aggression)
{
    this->width      = width;
    this->height     = height;
    this->aggression = aggression;

}

Vehicle::~Vehicle()
{

}

bool Vehicle :: decisionSpeedUp(){


}

bool Vehicle :: decisionSlowDown(){

}

bool Vehicle :: decisionOverTake(){

}


void Vehicle::speedUp(){
//Algorithm for Speeding up, same for every vehicle
//update i.e scan is the only one we need to provide a new implementation for each sub type of vehicle
//As the line of sight i.e. radar for motorbike is different to vehicle etc.....
cout << "speed up called";

}

void Vehicle::slowDown(){
 //Same as above
}

void Vehicle::overTake(){
 //Same as above
}
