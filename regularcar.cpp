#include "vehicle.h";
#include "regularcar.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "qmath.h"
#include <typeinfo>
#include <QDebug>
#include <iostream>
#include <QPen>
#include <iostream>
#include "trafficlights.h"
using namespace std;



//Performance monitoring methods, comment out in release
void timer::start() {
    begTime = clock();
}

unsigned long timer::elapsedTime() {
    return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
}

bool timer::isTimeout(unsigned long seconds) {
    return seconds >= elapsedTime();
}
timer performance_timer;


RegularCar::RegularCar(Subject *aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos,string direction, QGraphicsItem *parent):Vehicle(width,height,aggression,xStartingPos,yStartingPos,direction)
{
  //qDebug()<< xStartingPos;
  // Colin changed for debugging setPos(xStartingPos, yStartingPos);
  //setUp();
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

//Thread setup , correct way to do it, QT documentation is incorrect in subclassing from QThread
//i.e. QObject and move this object to qthread in main states
void RegularCar::DoThreadSetup(QThread &cThread, vector <Vehicle*> vehicles,trafficlights *trafficlight){
    //connect the signal emitted from the thread "starting" to the slot update
    this->vehicles = vehicles;
    this->trafficlight= trafficlight;
    connect(&cThread,SIGNAL(started()),this,SLOT(update()));
}

//Update no longer accepts vehicles as they are now threads, and you cannot
//pass data through this siganl and slot therefore we make a copy in do thread setup

void RegularCar::update(){ //Maybe only pass in vehicles that are in its scope

    //Performance monitoring methods, comment out in release
    performance_timer.start();
    //Only execute the following when the thread status is active
  while(this->getThreadStatus() == true){

  //Sleep thread for 100 ms every iteration
  QThread::currentThread()->msleep(100);
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  bool stopIfNearLights;
  //Colins - Thread Safety
   if(this->area->collidesWithItem(trafficlight)) {
       stopIfNearLights = true ;
   }
   else{
       stopIfNearLights = false;
   }


   if(trafficLightsOn){
       for(int i=0; i< vehicles.size();i++){
           //If lights are on and if the current car collides with a vehicle and that vehicle collides with the traffic lights and the lights are on
           if(this->area->collidesWithItem(vehicles.at(i)->area) && vehicles.at(i)->area->collidesWithItem(trafficlight))
               stopIfNearLights =true;
       }
   }


  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  if(trafficLightsOn == true && stopIfNearLights ==true){
  //stop
  }
  else{
  if(aggression ==  High){
  StrategyContext * context = new StrategyContext(new IncreaseSpeedAggressive());
  context->executeStrategyDecision(this->vehicles, this);
  context = new StrategyContext(new DecreaseSpeed());
  context->executeStrategyDecision(this->vehicles, this);
  context = new StrategyContext(new OvertakeHigh());
  context->executeStrategyDecision(this->vehicles, this);
  }

    if(aggression == Medium){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedMedium());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new OverTakeMedium());
    context->executeStrategyDecision(this->vehicles, this);
  }

  if(aggression == Low){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedLow());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(this->vehicles, this);
  }
  // Used for performance monitoring
  timesCalled++;

/*  //Performance monitoring methods, comment out in release
  unsigned long seconds = 5;
  cout << "\nelapsed time: "<<performance_timer.elapsedTime() << endl;
  if(performance_timer.elapsedTime() >= seconds) {
      cout<< "\nPerformance Monitoring timed stop \n";
      //Turn off all threads
      this->setThreadStatus(false);
      cout << "Total times vehicals have been called: " << timesCalled << "\n";

  }*/

 }
  }


}


