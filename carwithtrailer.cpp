#include "carwithtrailer.h"
#include "vehicle.h"
#include "subject.h"
carwithtrailer::carwithtrailer(Subject *aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos,string direction, QGraphicsItem *parent):Vehicle(width,height,aggression, xStartingPos, yStartingPos,direction )
{

  //this->topSpeed = 100;
  setPos(xStartingPos, yStartingPos);
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void carwithtrailer::update(){
  std::cout << "regular car scan ahead";

  //Call Methods
}

//Thread setup , correct way to do it, QT documentation is incorrect in subclassing from QThread
void carwithtrailer::DoThreadSetup(QThread &cThread, vector <Vehicle*> vehicles,trafficlights *trafficlight){
    //connect the signal emitted from the thread starting to the slot update
    this->vehicles = vehicles;
    this->trafficlight= trafficlight;
    connect(&cThread,SIGNAL(started()),this,SLOT(update(vehicles)));
}

void carwithtrailer::updateTrafficLightsSignal(bool trafficlights_On)
{
    trafficLightsOn = trafficlights_On;
}
