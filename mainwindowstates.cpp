#include "mainwindowstates.h"

//MainWindowStates::MainWindowStates()
//{
//}

AbstractState::~AbstractState()
{
}

void AbstractState::setState(MainWindow &mWindow, AbstractState *state)
{
    AbstractState *aux = mWindow.mState;
    mWindow.mState = state;
    delete aux;
}

Setup::~Setup()
{
}

void Setup::addRoad(MainWindow &mWindow)
{
    // code to add road here
}

void Setup::addVehicle(MainWindow &mWindow)
{
    // code to add vehicle here
}

void Setup::runSimulation(MainWindow &mWindow)
{
    // code to run simulation and change to simulation state
    std::cout<< "Running simulation " << std::endl;
    setState(mWindow, new Simulation());
}

void Setup::stopSimulation(MainWindow &mWindow)
{
    // throw error, Simulation is not running, nothing to stop

}
void Setup::viewReport(MainWindow &mWindow)
{
    // throw error, Simulation has not run yet, nothing to show
}

Simulation::~Simulation()
{
}

void Simulation::addRoad(MainWindow &mWindow)
{
    // throw error, Simulation already running
}
void Simulation::addVehicle(MainWindow &mWindow)
{
    //throw error, Simulation already running
}
void Simulation::runSimulation(MainWindow &mWindow)
{
    //throw error, Simulation already running
}
void Simulation::stopSimulation(MainWindow &mWindow)
{
    // code to stop simulation here
}
void Simulation::viewReport(MainWindow &mWindow)
{
    // throw error, Simulation is running, stop simulation first
}


ReportState::~ReportState()
{
}

void ReportState::addRoad(MainWindow &mWindow)
{
    // display message that state is being changed to Setup, press the add road button again
    setState(mWindow, new Setup());
}
void ReportState::addVehicle(MainWindow &mWindow)
{
    // display message that state is being changed to Setup, press the add road button again
    setState(mWindow, new Setup());
}
void ReportState::runSimulation(MainWindow &mWindow)
{
    // message, Running simulation with same roards and cars
    setState(mWindow, new Simulation());

}
void ReportState::stopSimulation(MainWindow &mWindow)
{
    // throw error, Simulation not running

}
void ReportState::viewReport(MainWindow &mWindow)
{
    // code to show report goes here
}
