#ifndef POLICECAR_H
#define POLICECAR_H
#include "vehicle.h"
#include "subject.h"

class PoliceCar : public Vehicle
{
public:
    PoliceCar(Subject *aVehicle,int width, int height, double aggression);
    void update();
//signals:

//public slots:
};

#endif // POLICECAR_H
