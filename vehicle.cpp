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


void Vehicle::createDispatcher()
{
    dis = Dispatcher();
}

bool Vehicle::getThreadStatus(){
    return doThread;
}

void Vehicle::setThreadStatus(bool status){
   doThread = status;
}
