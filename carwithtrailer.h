#ifndef CARWITHTRAILER_H
#define CARWITHTRAILER_H
#include "vehicle.h"
#include "subject.h"
#include <vector>

using namespace std;


class carwithtrailer : public Vehicle
{
public:
    carwithtrailer(Subject *aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos, string direction, QGraphicsItem *parent =0);
    void DoThreadSetup(QThread &cThread, vector<Vehicle *> vehicles, trafficlights *trafficlight);
//signals:

public slots:
    void update();
};


#endif // CARWITHTRAILER_H
