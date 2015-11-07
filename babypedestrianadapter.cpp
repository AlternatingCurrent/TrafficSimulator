#include "babypedestrianadapter.h"
#include "babypedestrian.h"
#include "pedestrian.h"
#include <QTimer>

BabyPedestrianAdapter::BabyPedestrianAdapter(BabyPedestrian *aBaby)
{

    theBaby = aBaby;
    theBaby->setPos(800,250);

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

void BabyPedestrianAdapter::move2(int x, int yPos)
{
    theBaby->crawl(x, yPos);
}

void BabyPedestrianAdapter::delay()
{
    theBaby->delay();
}
//overridding move
void BabyPedestrianAdapter::move()
{
    int x=0, y=0;
    theBaby->crawl(x, y);

}

