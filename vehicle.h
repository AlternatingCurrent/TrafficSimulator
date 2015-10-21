#ifndef VEHICLE_H
#define VEHICLE_H

class Subject; //Forward declare to use pointer of type Subject
class Vehicle
{
public:
    Vehicle();
    virtual ~Vehicle();
    Subject * aVehicle;
    virtual void update() = 0; //Problems with vtables otherwise


//signals:

//public slots:
};

#endif // VEHICLE_H
