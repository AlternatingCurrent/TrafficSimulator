#ifndef POLICECAR_H
#define POLICECAR_H
#include "vehicle.h"
#include "subject.h"
#include <QGraphicsPixmapItem>
class PoliceCar : public Vehicle
{
public:
    PoliceCar(Subject *aVehicle,int width, int height, double aggression,QGraphicsItem *parent =0);
    void update();
    void setUp();
//signals:

//public slots:
};

#endif // POLICECAR_H
