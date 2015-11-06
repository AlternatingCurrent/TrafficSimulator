#ifndef OVERTAKEMEDIUM_H
#define OVERTAKEMEDIUM_H
#include "vehiclestrategy.h"
#include "vehicle.h"
#include <QPointF>
#include <QGraphicsItem>
class OverTakeMedium:public VehicleStrategy
{
public:
    OverTakeMedium();
    void decision(vector<Vehicle*> vehicles,  Vehicle * currentVehicle);
    void doOperation(Vehicle * currentVehicle);
    double distanceTo(QGraphicsItem *item, Vehicle *currentVehicle);
    int aquire_and_check(Vehicle * currentVehicle);
    bool check_whether_to_check_aquire_and_target(Vehicle * currentVehicle);
private:

signals:

public slots:
};

#endif // OVERTAKEMEDIUM_H
