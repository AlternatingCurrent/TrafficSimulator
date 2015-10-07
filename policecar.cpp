#include "policecar.h"

PoliceCar::PoliceCar(Subject * aVehicle)
{
 this->aVehicle = aVehicle;
 this->aVehicle->attach(this);
}

void PoliceCar::update(){
   std::cout << "PoliceCar Scan Ahead";
}
