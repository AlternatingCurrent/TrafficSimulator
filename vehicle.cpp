#include "vehicle.h"
#include <string>
#include <iostream>
#include <QGraphicsPixmapItem>
using namespace std;

Vehicle::Vehicle(int width, int height, int aggression, QGraphicsItem *parent)
{
    this->width      = width;
    this->height     = height;
    this->aggression = aggression;
    speedLimit = 120;

}

Vehicle::~Vehicle()
{

}

bool Vehicle :: decisionSpeedUp(){

    return false;
}

bool Vehicle :: decisionSlowDown(){
    return false;
}

bool Vehicle :: decisionOverTake(){
    return false;
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
