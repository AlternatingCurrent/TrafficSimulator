#ifndef REGULARCAR_H
#define REGULARCAR_H
#include "vehicle.h"
#include "subject.h"
#include <vector>
#include <time.h>

using namespace std;


class timer {
    private:
        unsigned long begTime;
    public:
        void start();
        unsigned long elapsedTime();
        bool isTimeout(unsigned long seconds);
};

class RegularCar : public Vehicle
{
    Q_OBJECT
public:
    RegularCar(Subject *aVehicle, int width, int height, double aggression,  int xStartingPos, int yStartingPos, string direction, QGraphicsItem * parent = 0);
    void DoThreadSetup(QThread &cThread, vector<Vehicle *> vehicles, trafficlights *trafficlight);
    void updateTrafficLightsSignal(bool trafficlights_On);
//signals:

public slots:
    void update();
};

#endif // REGULARCAR_H
