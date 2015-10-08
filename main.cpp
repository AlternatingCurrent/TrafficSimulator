#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include "vehicle.h"
#include "subject.h"
#include "policecar.h"
#include "regularcar.h"

using namespace std;
int main(int argc, char *argv[])
{
    //cout << "Hello\n\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.beginSimulation();
    return a.exec();
    Subject * asubject = new Subject();

    Vehicle * aCar = new PoliceCar(asubject);
    Vehicle * car2 = new RegularCar(asubject);

    cout << "Before set state 5";
            asubject->setState(5);
    cout << "Before set state 100";
            asubject->setState(100);


}
