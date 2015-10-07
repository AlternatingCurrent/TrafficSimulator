#ifndef POLICECAR_H
#define POLICECAR_H
#include "vehicle.h"
#include "subject.h"

class PoliceCar : public Vehicle
{
public:
    PoliceCar(Subject *aVehicle);
    void update();
//signals:

//public slots:
};

#endif // POLICECAR_H
