#include "regularcar.h"

RegularCar::RegularCar(Subject *aVehicle, int width, int height, double aggression):Vehicle(width,height,aggression)
{
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void RegularCar::update(){
  std::cout << "regular car scan ahead";

  //Call Methods
}

