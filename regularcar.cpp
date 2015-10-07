#include "regularcar.h"

RegularCar::RegularCar(Subject *aVehicle)
{
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void RegularCar::update(){
  std::cout << "regular car scan ahead";
}
