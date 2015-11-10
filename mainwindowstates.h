#ifndef MAINWINDOWSTATES_H
#define MAINWINDOWSTATES_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pedestrian.h"
#include "pedestrianmaker.h"
#include "loggingapp.h"
#include <QThread>
#include <QObject>

//class MainWindowStates
//{
//public:
//    MainWindowStates();
//};

class MainWindow;


//Qbject for signals and slots
class AbstractState : public QObject{
public:
    virtual void addRoad(MainWindow &mWindow,Ui::MainWindow *ui ) = 0;
    virtual void addVehicle(MainWindow &mWindow,Ui::MainWindow *ui ) = 0;
    virtual void runSimulation(MainWindow &mWindow,Ui::MainWindow  *ui ) = 0;
    virtual void stopSimulation(MainWindow &mWindow ,Ui::MainWindow * ui) = 0;
    virtual void viewReport(MainWindow &mWindow,Ui::MainWindow * ui ) = 0;
    virtual void startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui ) = 0;
    virtual void addPedestrain(MainWindow &mWindow,Ui::MainWindow * ui ) = 0;
    virtual ~AbstractState();

protected:
    void setState(MainWindow &mWindow, AbstractState *state);
    // will have to add other methods such as draw in here

};

class Setup : public AbstractState  {
public:
    virtual void addRoad(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addVehicle(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void runSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void viewReport(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addPedestrain(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual ~Setup();

};

class Simulation  : public AbstractState{
    //Declare meta object so we can use signals and slots
    Q_OBJECT
public:
    virtual void addRoad(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addVehicle(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void runSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void viewReport(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addPedestrain(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual ~Simulation();


public slots:

    //To update vehciles positions as they are in separate threads
    void recieveNewVehiclePositions(Vehicle * currentVehicle,int x, int y);
     void trafficLightsCheck();

};

class ReportState  : public AbstractState {
public:
    virtual void addRoad(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addVehicle(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void runSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void viewReport(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual void addPedestrain(MainWindow &mWindow,Ui::MainWindow * ui );
    virtual ~ReportState();

};


#endif // MAINWINDOWSTATES_H
