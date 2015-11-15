#include "overtakehigh.h"
#include <iostream>
#include <QDebug>
OvertakeHigh::OvertakeHigh()
{

}

void OvertakeHigh :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
     bool isColliding = false;

    for(int i=0; i<vehicles.size(); i++){
    //make sure we are not looking at the current vehicle inside in the vector
    if(currentVehicle->pos() !=vehicles.at(i)->pos()){


      if((currentVehicle->area->collidesWithItem((vehicles.at(i)->area))) &&(currentVehicle->pos().x() < vehicles.at(i)->pos().x()) && (currentVehicle->pos().y() == currentVehicle->getOriginalY())
              && (vehicles.at(i)->aggression != currentVehicle->High) ){
          qDebug()<<"Call Overtaking";
            if(vehicles.at(i)->isOvertaking == true && vehicles.at(i)->pos().y() > currentVehicle->pos().y()){

            }else{
            doOperation(currentVehicle);
            }
       }

      //Find out if vehicle is collidinf with a vehicle on the left
      if(currentVehicle->isOvertaking==true &&currentVehicle->area->collidesWithItem(vehicles.at(i)->area) && vehicles.at(i)->pos().y() == vehicles.at(i)->getOriginalY()){ //Causes car to move to the left right away&& (vehicles.at(i)->pos().y() == vehicles.at(i)->getOriginalY()) ){
             isColliding = true; }
     }
    }

    //move back in if you are not collidng with any vehicles on the left
    if((currentVehicle->pos().y() == currentVehicle->getOriginalY()+100) && (isColliding == false)){
      //   currentVehicle->setPos((currentVehicle->pos().x()), (currentVehicle->pos().y()-50));
        emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,currentVehicle->pos().x(),currentVehicle->pos().y()-100);
        currentVehicle->isOvertaking = false;
        qDebug()<<"Push In";

    }

  }

void OvertakeHigh :: doOperation(Vehicle * currentVehicle){
       qDebug()<<"Overtaking";
       emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,currentVehicle->pos().x(),currentVehicle->pos().y()+100);
       currentVehicle->isOvertaking = true;

       //Interceptor code here, need to log the overtaking
       //First create the context object with the currect speed
       currentVehicle->cObj = ContextObject(currentVehicle->currentSpeed);
       //Now pass the context object to the dispatcher to be recorded
       currentVehicle->dis.callback(&currentVehicle->cObj);
 }
