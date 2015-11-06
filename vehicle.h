#ifndef VEHICLE_H
#define VEHICLE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "dispatcher.h"
#include "contextobject.h"
#include "increasespeedaggressive.h";
#include "increasespeedlow.h";
#include "increasespeedmedium.h";
#include "decreasespeed.h";
#include "overtakehigh.h";
#include "overtakelow.h";
#include "overtakemedium.h";

#include <vector>

using namespace std;

#include "StrategyContext.h";

class Subject; //Forward declare to use pointer of type Subject
//Abstract class Vehcile provides the base information for all subtypes
class Vehicle: public QObject, public QGraphicsPixmapItem{
    friend class ContextObject;
    Q_OBJECT
public:


    //***********METHODS*********************:

    Vehicle(int width, int height, int aggression, int xStartingPos, int yStartingPos, QGraphicsItem * parent=0); //changed
    virtual ~Vehicle();
    Subject * aVehicle;

    //Update will act as the vehicles scan method
    //Problems with vtables otherwise
    //Don't need to be virtual only update as update is part of observer
    //Who dosn't know what type of vehicle until runtime i.e dynamic binding

    virtual void update(vector <Vehicle*> vehicles) = 0;
    //virtual void increaseSpeed(); //Algorithm to inc/dec speed of the currentvehicle be it car, motorbioke etc.
    //virtual void decreaseSpeed();
     QGraphicsRectItem * area;

    //general functions of a vehicle
    //reduce code duplication through inheritance
    //if we need any other functionality we can just inmplement it in the subclasses
    virtual void setUp();
    void speedUp();
    void slowDown();
    void overTake();

    bool decisionSlowDown();
    bool decisionSpeedUp();
    bool decisionOverTake();

    //Returns positions of vehicles around its field of view
    //string viewFieldOfView();


    //***********VARIABLES*****************:
    //Range of view will act as a radius in which the drivers can see
    int rangeOfView;

    enum vehcileAttributes {HeightOfVehicle, WidthOfCar};
    enum Aggressiveness    {Low = 1 , Medium = 2, High = 3};
    enum topSpeeds         {LowAggressiveTopSpeed = 60, MediumAggressiveTopSpeed = 100, HighAggressiveTopSpeed = 160};
    //Aggrassive drivers will still try and increase speed/overtake in a smallopening
    //and respectively non-aggresive drivers will be more cautious
    enum Distances         {SmallOpening = 30, MediumOpening = 60, LargeOpening = 100, OverTakingDistance = 200};
    //OverTakingRange = Average distance from oncomming traffic that somebody would overtake

    /*Aggression can be 1/2/3
    1 = Low
    2 = Medium
    3 = High
    */
    int aggression;
    int width;
    int height;
    int currentSpeed = 0;
    bool isOvertaking;
    int xStartingPos;
    int yStartingPos;
    //Add this to the constructor so it can change
    //And thus change the outcome of the simulation
    int speedLimit;

    //Interceptor vairables and methods
    Dispatcher dis;
    ContextObject cObj;
    void createDispatcher();


//signals:

//public slots:
};

#endif // VEHICLE_H
