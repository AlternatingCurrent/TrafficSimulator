#ifndef REGULARCAR_H
#define REGULARCAR_H
#include "vehicle.h"
#include "subject.h"

class RegularCar : public Vehicle
{
public:
    RegularCar(Subject *aVehicle);
    //Dont need update() here as it is virtual() just provide implementation
    void update();
//signals:

//public slots:
};

#endif // REGULARCAR_H
