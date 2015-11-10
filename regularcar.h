#ifndef REGULARCAR_H
#define REGULARCAR_H
#include "vehicle.h"
#include "subject.h"
#include <vector>

using namespace std;

class RegularCar : public Vehicle
{
    Q_OBJECT
public:
    RegularCar(Subject *aVehicle,int width, int height, double aggression,  int xStartingPos, int yStartingPos, QGraphicsItem * parent = 0);
    //Dont need update() here as it is virtual() just provide implementation
    void DoThreadSetup(QThread &cThread, vector<Vehicle *> vehicles);
    void setUp();
    //QGraphicsRectItem * area;
//signals:

public slots:
    void update();
};

#endif // REGULARCAR_H
