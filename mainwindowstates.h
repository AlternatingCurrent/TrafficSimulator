#ifndef MAINWINDOWSTATES_H
#define MAINWINDOWSTATES_H
#include "mainwindow.h"

//class MainWindowStates
//{
//public:
//    MainWindowStates();
//};

class MainWindow;

class AbstractState {
public:
    virtual void addRoad(MainWindow &mWindow ) = 0;
    virtual void addVehicle(MainWindow &mWindow ) = 0;
    virtual void runSimulation(MainWindow &mWindow ) = 0;
    virtual void stopSimulation(MainWindow &mWindow ) = 0;
    virtual void viewReport(MainWindow &mWindow ) = 0;
    virtual ~AbstractState();

protected:
    void setState(MainWindow &mWindow, AbstractState *state);
    // will have to add other methods such as draw in here

};

class Setup : public AbstractState {
public:
    virtual void addRoad(MainWindow &mWindow );
    virtual void addVehicle(MainWindow &mWindow );
    virtual void runSimulation(MainWindow &mWindow );
    virtual void stopSimulation(MainWindow &mWindow );
    virtual void viewReport(MainWindow &mWindow );
    virtual ~Setup();

};

class Simulation  : public AbstractState {
public:
    virtual void addRoad(MainWindow &mWindow );
    virtual void addVehicle(MainWindow &mWindow );
    virtual void runSimulation(MainWindow &mWindow );
    virtual void stopSimulation(MainWindow &mWindow );
    virtual void viewReport(MainWindow &mWindow );
    virtual ~Simulation();

};

class ReportState  : public AbstractState {
public:
    virtual void addRoad(MainWindow &mWindow );
    virtual void addVehicle(MainWindow &mWindow );
    virtual void runSimulation(MainWindow &mWindow );
    virtual void stopSimulation(MainWindow &mWindow );
    virtual void viewReport(MainWindow &mWindow );
    virtual ~ReportState();

};


#endif // MAINWINDOWSTATES_H
