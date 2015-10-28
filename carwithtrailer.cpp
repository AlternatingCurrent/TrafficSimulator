#include "carwithtrailer.h"
#include "vehicle.h"
#include "subject.h"
carwithtrailer::carwithtrailer(Subject *aVehicle, int width, int height, double aggression):Vehicle(width,height,aggression)
{
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void carwithtrailer::update(){
  std::cout << "regular car scan ahead";

  //Call Methods
}

