#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include "vehicle.h"
#include "subject.h"
#include "policecar.h"
#include "regularcar.h"
#include "vehiclestrategy.h"
#include "increasespeedaggressive.cpp"
#include "simulationframe.h"
#include "vehiclefactory.h"
#include "randomgenerator.h"
SimulationFrame * sim;
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.beginSimulation();
    return a.exec();



}
