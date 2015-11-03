#include "vehiclefactory.h"
#include "vehicle.h"
#include "vehiclefactory.h"
#include "regularcar.h"
#include "policecar.h"
#include "carwithtrailer.h"
#include <time.h>
#include "subject.h"
#include <QDebug>
#include <random>
#include "randomgenerator.h"
using namespace std;
//struct RandomGenerator/*::RandomGenerator*/
//{

//   mt19937 _engine;
//   uniform_int_distribution<int> _dist;

//   RandomGenerator(int start, int end)
//           :_engine {random_device{} ()},
//             _dist(start, end)
//   {

//}

//int createRandomNumber()
//{
//  //qDebug()<< "result" << _dist(_engine) ;
// return _dist(_engine);

//}
//};

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
//    RandomGenerator * ranGen = new RandomGenerator(1,3);
//    int randomNumber =0;
//    randomNumber = ranGen->createRandomNumber();
    RandomGenerator * ranGen;
      int randomNumber =0;
      randomNumber = ranGen->createRandomNumber(1,3);

    qDebug()<< "result" << randomNumber ;
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

