#ifndef CARWITHTRAILER_H
#define CARWITHTRAILER_H
#include "vehicle.h"
#include "subject.h"
class carwithtrailer : public Vehicle
{
public:
    carwithtrailer(Subject *aVehicle,int width, int height, double aggression, QGraphicsItem *parent =0 );
    //Dont need update() here as it is virtual() just provide implementation
    void update();
    void setUp();
//signals:

//public slots:
};


#endif // CARWITHTRAILER_H
