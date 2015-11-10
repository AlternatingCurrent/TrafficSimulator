#include "vehicle.h"
#include <string>
#include <iostream>
#include <QGraphicsPixmapItem>
using namespace std;

Vehicle::Vehicle(int width, int height, int aggression, int xStartingPos, int yStartingPos, QGraphicsItem *parent)
{
    this->width      = width;
    this->height     = height;
    this->aggression = aggression;
    speedLimit = 120;
    this->xStartingPos = xStartingPos;
    this->yStartingPos = yStartingPos;
    timesCalled = 0;

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

    //Interceptor code here, need to log the overtaking
    //First create the context object with the currect speed
    cObj = ContextObject(currentSpeed);
    //Now pass the context object to the dispatcher to be recorded
    dis.callback(&cObj);
}
void Vehicle::createDispatcher()
{
    dis = Dispatcher();
}
void Vehicle::setUp()
{

}



bool Vehicle::getThreadStatus(){
    return doThread;
}

void Vehicle::setThreadStatus(bool status){
   doThread = status;
}
