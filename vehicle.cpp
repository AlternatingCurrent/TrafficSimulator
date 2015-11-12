#include "vehicle.h"
#include <string>
#include <iostream>
#include <QDebug>
#include <QGraphicsPixmapItem>
using namespace std;

Vehicle::Vehicle(int width, int height, int aggression, int xStartingPos, int yStartingPos, string direction, QGraphicsItem *parent)
{
    this->width      = width;
    this->height     = height;
    this->aggression = aggression;
    speedLimit = 120;
    this->xStartingPos = xStartingPos;
    this->yStartingPos = yStartingPos;
    timesCalled = 0;
    this->direction      = direction;
}

Vehicle::~Vehicle()
{

}

void Vehicle::updateTrafficLightsSignal(bool trafficlights_On)
{

  // qDebug()<<"in here trafficlightsSignal is on is "<< trafficlights_On;
//    trafficLightsOn = trafficlights_On;
   // qDebug()<<"In the vehcile class and trafficlights is on is "<< trafficLightsOn ;
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

int Vehicle::getOriginalX(){
    return xStartingPos;
}

int Vehicle::getOriginalY(){
    return yStartingPos;
}



