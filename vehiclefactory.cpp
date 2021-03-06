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
   //    vehicle = new RegularCar(asubject,0,0,0.0,0,0);//this has to be changed (0,0,0);
       return vehicle;
    }
    else if(type == policecar){

     //    vehicle = new PoliceCar(asubject,0,0,0.0,0,0);//this has to be changed (0,0,0);
         return vehicle;

    }
    else if(type == cartrailer){

      //  vehicle = new carwithtrailer(asubject,0,0,0.0,0,0);
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
     //   vehicle = new RegularCar(asubject,0,0,0.0,0,0);//this has to be changed (0,0,0);
        return vehicle;
            break;
        case 2:
     //   vehicle = new PoliceCar(asubject,0,0,0.0,0,0);//this has to be changed (0,0,0);
        return vehicle;
            break;
        case 3:
     //   vehicle = new PoliceCar(asubject,0,0,0.0,0,0);//this has to be changed (0,0,0);
        return vehicle;
            break;
    }
}


Vehicle *VehicleFactory::createVehicle(QString type, string aggressiveness, int xPosition, int yPosition, Subject * subject,QGraphicsScene *scene, string direction)  //obviously need to decide exactly what we can do here
{
 if(aggressiveness == "Low"){
     aggressive = 1;
 }
 if(aggressiveness == "Medium"){
     aggressive = 2;
 }
 if(aggressiveness == "High"){
     aggressive = 3;
 }

    Vehicle * vehicle;
    QString redcar ="regularcar", policecar = "policecar", cartrailer = "carwithtrailer";
    if(type == redcar){
       vehicle = new RegularCar(subject,50,50,aggressive,xPosition,yPosition,direction);
       if(direction == "west"){
           vehicle= setup(vehicle,"carRedLeft.png",xPosition,yPosition);
       }
         else{
       vehicle= setup(vehicle,"carRedRight.png",xPosition,yPosition);
       }

       vehicle->setPos(xPosition, yPosition);

       return vehicle;
    }
    else if(type == policecar){

         vehicle = new PoliceCar(subject,50,50,aggressive,xPosition,yPosition,direction);
         if(direction == "west"){
             vehicle= setup(vehicle,"policeLeft.png",xPosition,yPosition);
         }
           else{
         vehicle= setup(vehicle,"police.png",xPosition,yPosition);
         }

         vehicle->setPos(xPosition, yPosition);
         return vehicle;

    }
    else if(type == cartrailer){

        vehicle = new carwithtrailer(subject,50,50,aggressive,xPosition,yPosition,direction);
        if(direction == "west"){
            vehicle= setup(vehicle,"cartrailerLeft.png",xPosition,yPosition);
        }
          else{
        vehicle= setup(vehicle,"cartrailer.png",xPosition,yPosition);
        }
        vehicle->setPos(xPosition, yPosition);
        return vehicle;
    }
    else{
    }
    scene->addItem(vehicle);


}

VehicleFactory::~VehicleFactory()
{

}

Vehicle *VehicleFactory::setup(Vehicle *vehicle, QString type, int x, int y)
{
    QPixmap watermark(":/"+type); //changed
    QPixmap newPixmap = watermark.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    vehicle->setPixmap(newPixmap);
    QRectF rect(0,-60,200,100);
    QRectF rect_for_overtaking(0,50,700,30);
    vehicle->area = new QGraphicsRectItem(rect,vehicle);
    vehicle->area_to_check_for_overtaking = new QGraphicsRectItem(rect_for_overtaking, vehicle);
    //vehicle-> area->setPen(QPen(Qt::white));
    vehicle-> area->setPos(vehicle->x()-30,vehicle->y()+25);
    vehicle->area_to_check_for_overtaking->setPos(vehicle->x()-30,vehicle->y()+25);
    return vehicle;
}

