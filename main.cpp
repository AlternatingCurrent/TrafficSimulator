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

using namespace std;
int main(int argc, char *argv[])
{
    //cout << "Hello\n\n";
    QApplication a(argc, argv);
   // Subject * asubject = new Subject();
   // Vehicle * aCar = new PoliceCar(asubject,50,50,2);
   // Vehicle * car2 = new RegularCar(asubject,50,50,1);

  //  cout << aCar->width;
  //   cout << car2->width;
  //  aCar->speedUp();
  //  cout << "Before set state 5";
   //         asubject->setState(5);
  //  cout << "Before set state 100";
   //         asubject->setState(100);

    VehicleStrategy *f = new IncreaseSpeedAggressive();

    MainWindow w;
    w.show();
    w.beginSimulation();
    return a.exec();



}
