#include "babypedestrianadapter.h"
#include "babypedestrian.h"
#include "pedestrian.h"
#include <QTimer>

BabyPedestrianAdapter::BabyPedestrianAdapter(BabyPedestrian *aBaby)
{

    theBaby = aBaby;
}

BabyPedestrianAdapter::~BabyPedestrianAdapter()
{

}

double BabyPedestrianAdapter::getMaxRange()
{
    return theBaby->getMaxRange();
}

double BabyPedestrianAdapter::getDistanceTravelled()
{
    return theBaby->getDistanceCrawled();
}

void BabyPedestrianAdapter::setMaxRange(double range)
{
    theBaby->setMaxRange(range);
}

void BabyPedestrianAdapter::setDistanceTravelled(double dist)
{
    theBaby->setDistanceCrawled(dist);
}


void BabyPedestrianAdapter::setSpeed(int speed)
{
    theBaby->setCrawlSpeed(speed);
}

int BabyPedestrianAdapter::getSpeed()
{
   return theBaby->getCrawlSpeed();
}
//overridding move
void BabyPedestrianAdapter::move()
{
    theBaby->crawl();
}

