#ifndef POLICECAR_H
#define POLICECAR_H
#include "vehicle.h"
#include "subject.h"
#include <QObject>
#include <QGraphicsPixmapItem>

#include <vector>

using namespace std;


class PoliceCar : public Vehicle
{
    Q_OBJECT
public:
    PoliceCar(Subject *aVehicle,int width, int height, double aggression,QGraphicsItem *parent =0);
    void update(vector<Vehicle*> vehicles);
    void setUp();
//signals:

//public slots:
};

#endif // POLICECAR_H
