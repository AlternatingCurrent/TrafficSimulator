#include "policecar.h"
#include <QGraphicsPixmapItem>

PoliceCar::PoliceCar(Subject * aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos,string direction, QGraphicsItem *parent):Vehicle(width,height,aggression, xStartingPos, yStartingPos,direction)
{
    setPos(xStartingPos, yStartingPos);
 //   setUp();
// this->topSpeed = 120; //REVIEW WITH AARON AND JUAN, WILL WE ADD IT AS A PARAMETER OR HAVE IT SET
 this->aVehicle = aVehicle;
 this->aVehicle->attach(this);
}

void PoliceCar::update(){
   std::cout << "PoliceCar Scan Ahead";
   //Does all the checks from vehicle
   //When somebody is speeding we can just add a method call
   //when the interceptor logs this
}


//Thread setup , correct way to do it, QT documentation is incorrect in subclassing from QThread
void PoliceCar::DoThreadSetup(QThread &cThread, vector <Vehicle*> vehicles,trafficlights *trafficlight){
    //connect the signal emitted from the thread starting to the slot update
    this->vehicles = vehicles;
    this->trafficlight= trafficlight;
    connect(&cThread,SIGNAL(started()),this,SLOT(update(vehicles)));
}

void PoliceCar::updateTrafficLightsSignal(bool trafficlights_On)
{
    trafficLightsOn = trafficlights_On;
}
