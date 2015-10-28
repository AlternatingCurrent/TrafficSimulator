#include "vehiclefactory.h"
#include "vehicle.h"
#include "vehiclefactory.h"
#include "regularcar.h"
#include "policecar.h"
#include "carwithtrailer.h"
#include <time.h>
#include "subject.h"
#include "randomgenerator.h"
VehicleFactory::VehicleFactory()
{
    asubject = new Subject();
}

Vehicle *VehicleFactory::createVehicle(QString type)
{

    Vehicle * vehicle;
    QString redcar ="regularcar", policecar = "policecar", cartrailer = "carwithtrailer";
    if(type == redcar){
       vehicle = new RegularCar(asubject,0,0,0.0);//this has to be changed (0,0,0);
       return vehicle;
    }
    else if(type == policecar){

         vehicle = new PoliceCar(asubject,0,0,0.0);//this has to be changed (0,0,0);
         return vehicle;

    }
    else if(type == cartrailer){

        vehicle = new carwithtrailer(asubject,0,0,0.0);
        return vehicle;
    }
    else{
    }
}
Vehicle *VehicleFactory::createRandomVehicle()
{

    Vehicle * vehicle;
    RandomGenerator * ranGen = new RandomGenerator();
    int randomNumber = ranGen->createRandomNumber(1,3);
    //trying to minimise if statments
    switch(randomNumber == 1) {
        case 1:
        vehicle = new RegularCar(asubject,0,0,0.0);//this has to be changed (0,0,0);
        return vehicle;
            break;
        case 2:
        vehicle = new PoliceCar(asubject,0,0,0.0);//this has to be changed (0,0,0);
        return vehicle;
            break;
        case 3:
        vehicle = new PoliceCar(asubject,0,0,0.0);//this has to be changed (0,0,0);
        return vehicle;
            break;
    }
}


Vehicle *VehicleFactory::createVehicle(QString type, QString Aggressiveness, QString startingSpeed)  //obviously need to decide exactly what we can do here
{

}

VehicleFactory::~VehicleFactory()
{

}

