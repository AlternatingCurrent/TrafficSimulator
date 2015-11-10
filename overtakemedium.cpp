#include "overtakemedium.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPointF>
#include <QLineF>
#include <QGraphicsRectItem>
OverTakeMedium::OverTakeMedium()
{

}

void OverTakeMedium :: decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle){
    bool isColliding = false;

    for(int i=0; i<vehicles.size(); i++){

    //make sure we are not looking at the current vehicle inside in the vector
    if(currentVehicle->pos() !=vehicles.at(i)->pos() ){

        //change 450
        //Will only be able to overtake low aggressive drivers
       if((currentVehicle->area->collidesWithItem((vehicles.at(i)->area))) &&(currentVehicle->pos().x() < vehicles.at(i)->pos().x()) &&
       (currentVehicle->pos().y() ==   450)  && (vehicles.at(i)->aggression == currentVehicle->Low)){ //could be affected by juans change
           doOperation(currentVehicle);
       }

    //See if vehicle is colliding with any vehicle on the left hand side of the road
    if( currentVehicle->area->collidesWithItem(vehicles.at(i)->area) && (vehicles.at(i)->pos().y() == 450) ){//could be affected by juans change
           isColliding = true;
    }
    }
    }
    //We can move back in if we are no longer colliding with any vehicles
    if((currentVehicle->isOvertaking == true) && (isColliding == false) ){ //make sure not colliding down the line
         //currentVehicle->setPos((currentVehicle->pos().x()), (currentVehicle->pos().y()-50));
         emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,currentVehicle->pos().x(),currentVehicle->pos().y()-50);
         currentVehicle->isOvertaking = false;
    }
  }


void OverTakeMedium :: doOperation(Vehicle * currentVehicle){
       emit currentVehicle->dispatchNewVehiclePositions(currentVehicle,currentVehicle->pos().x(),currentVehicle->pos().y()+50);
        currentVehicle->isOvertaking = true;


        //Interceptor code here, need to log the overtaking
        //First create the context object with the currect speed
        currentVehicle->cObj = ContextObject(currentVehicle->currentSpeed);
        //Now pass the context object to the dispatcher to be recorded
        currentVehicle->dis.callback(&currentVehicle->cObj);
}

double OverTakeMedium::distanceTo(QGraphicsItem *item, Vehicle * currentVehicle)
{
    QLineF ln(currentVehicle->pos(),item->pos());
    return ln.length();
}

//when overtaking is = true then do not check "aquire_and_check"
int OverTakeMedium::aquire_and_check(Vehicle * currentVehicle) //should only be called when the vehicle is in other lane to check whether they should move back in or not
{

 QList<QGraphicsItem *> colliding_items = currentVehicle->area_to_check_for_overtaking->collidingItems();

 if (colliding_items.size() == 1){

     return 1;
    }

     double closest_dist = 500; //distance to check ahead whether its safe to overtake ^^ this may have to be adjusted this number
     QPointF closest_pt = QPointF(0,0);
     for (size_t i = 0, n = colliding_items.size(); i < n; i++){
         Vehicle * vehicle = dynamic_cast<Vehicle *>(colliding_items[i]);
         if (vehicle){
             double this_dist = distanceTo(vehicle, currentVehicle);
             if(this_dist > closest_dist || (vehicle->yStartingPos == currentVehicle->yStartingPos)) //checking to see if its a car in front and its overtaking
             {

                 return 1; //overtake;
             }
             else{

                 return 0;
             }
         }
     }
}
 //check whether or not to move to opposite lane to check whether the car should overtake or not
bool check_whether_to_check_aquire_and_target(Vehicle *currentVehicle)
{

//    QList<QGraphicsItem *> colliding_items = currentVehicle->area->collidingItems();
//        double closest_dist = 500; //distance to check ahead whether its safe to overtake
//        QPointF closest_pt = QPointF(0,0);
//        for (size_t i = 0, n = colliding_items.size(); i < n; i++){
//            Vehicle * vehicle = dynamic_cast<Vehicle *>(colliding_items[i]);
//            if (vehicle->pos().y() > currentVehicle->pos().y() ){ //check on the y axis if its to the right
//         //^^ might have to change this y might have to be less than not sure tb tested
//                //then there is a vehicle to the right so do not check to overtake
//                return false;
//            }
//        }
}


