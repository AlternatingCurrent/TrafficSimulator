#ifndef VEHICLE_H
#define VEHICLE_H
#include <QThread>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "dispatcher.h"
#include "contextobject.h"
#include "increasespeedaggressive.h"
#include "increasespeedlow.h"
#include "increasespeedmedium.h"
#include "decreasespeed.h"
#include "overtakehigh.h"
#include "overtakelow.h"
#include "overtakemedium.h"
#include "StrategyContext.h"
#include <vector>

using namespace std;



class trafficlights;
class StrategyContext;
class Subject; //Forward declare to use pointer of type Subject
//Abstract class Vehcile provides the base information for all subtypes
class Vehicle: public QObject, public QGraphicsPixmapItem{
    friend class ContextObject;
    Q_OBJECT
public:


    //***********METHODS*********************:

    Vehicle(int width, int height, int aggression, int xStartingPos, int yStartingPos, string direction, QGraphicsItem * parent=0); //changed
    virtual ~Vehicle();
    Subject * aVehicle;

    //Need a copy for each thread
    vector <Vehicle*> vehicles;

    //NB
    //Because we cannot pass data when we start the thread, we need to pass
    //the vehicles which will be used into the vehicle class into a thread setup class, rather than passing them
    //to the update method through a pointer, i.e. each thread needs its own deep copy of the vehicles
    //to prevent any race conditions or crashes
    virtual void DoThreadSetup(QThread &cThread, vector<Vehicle *> vehicles, trafficlights *trafficlight) = 0;
    virtual void updateTrafficLightsSignal(bool trafficlights_On)=0;

    //Delete here as setup has moved
     QGraphicsRectItem * area;
     QGraphicsRectItem * area_to_check_for_overtaking;

    //Start and stop the threads
    bool getThreadStatus();
    void setThreadStatus(bool status);

    int getOriginalX();
    int getOriginalY();

    //***********VARIABLES*****************:
    string direction;
    enum vehcileAttributes {HeightOfVehicle, WidthOfCar};
    enum Aggressiveness    {Low = 1 , Medium = 2, High = 3};
    enum topSpeeds         {LowAggressiveTopSpeed = 60, MediumAggressiveTopSpeed = 100, HighAggressiveTopSpeed = 160};
    enum Distances         {SmallOpening = 30, MediumOpening = 60, LargeOpening = 100, OverTakingDistance = 200};
    //OverTakingRange = Average distance from oncomming traffic that somebody would overtake

    /*Aggression can be 1/2/3
    1 = Low
    2 = Medium
    3 = High
    */
    bool isStopped;
    bool trafficLightsOn;
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

    trafficlights * trafficlight;

    //Interceptor vairables and methods
    Dispatcher dis;
    ContextObject cObj;
    void createDispatcher();

    //Decides when to start and stop the thread
    bool doThread;

    //Keeps a track of how many times this vehicle's update method was called for performance montoring
    int timesCalled;

    StrategyContext * context;

signals:
    //Very important, since the main thread is the only one able to
    //access the UI we need to pass the updated vehicle positions to
    //the main window, unlike previously, we updated the positions from the strategy classes
    //therefore we will call the vehicles dispatch vehicle postions to update the ui instead
    void dispatchNewVehiclePositions(Vehicle * currentVehicle,int x, int y);

public slots:

    //Update will act as the vehicles scan method
    //Problems with vtables otherwise
    //Don't need to be virtual only update as update is part of observer
    //Who dosn't know what type of vehicle until runtime i.e dynamic binding

    virtual void update() = 0;
};

#endif // VEHICLE_H
