#ifndef PEDESTRIANMAKER_H
#define PEDESTRIANMAKER_H
#include "pedestrian.h"
#include "babypedestrian.h"
class pedestrianmaker
{
public:
    pedestrianmaker();
    ~pedestrianmaker();
    pedestrian * makeRandomPedestrian(QGraphicsScene *scene);
    pedestrian * makePedestrian(QString pedestrianType);
};


#endif // PEDESTRIANMAKER_H
