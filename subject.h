#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <iostream>
#include <string>
#include "vehicle.h"

class Subject
{
public:
    Subject();
    int getState();
    void setState(int state);
    void attach(Vehicle *aVehicle);
    void notifyAllVehicles();

private:
    //STD if not using std
    std::vector <Vehicle*> vehicles;
    int state;


//signals:

//public slots:
};

#endif // SUBJECT_H
