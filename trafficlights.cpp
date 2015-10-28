#include "trafficlights.h"
#include "QPixmap"
#include <QTimer>
#include <QVector>
#include <QPointF> //rep by floating point nos
#include <QRectF>
#include "pedestrian.h"
#include "simulationframe.h"
#include <QLineF>
#include <vehicle.h>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "MainWindow.h"
#include "athlete.h"
#include "pedestrianmaker.h"
extern SimulationFrame * sim;

trafficlights::trafficlights(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setUp();
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(50);
    destination= QPointF(800,0);
    traffic_light_concurrency_timer();

}

double trafficlights::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();

}

void trafficlights::cross_road(int pedestrianNo)
{

    if(pedestrianCount >= pedestrianNo){
        return;
    }
    else{
    pedestrianmaker * pedmaker = new pedestrianmaker();
    pedestrian  * ped ;
    ped =pedmaker->makeRandomPedestrian();
    ped->setPos(x()+20,y()+60);
    QLineF ln(QPointF(x(),y()),destination);
    int angle = -1* ln.angle(); //must be made clockwiese *-1
    sim->scene->addItem(ped);                                      //this need to be fixed undefined refernce?? not sure why
    pedestrianCount+=1;
    }

}

bool trafficlights::getTrafficLightsState()
{
    return trafficLightOn;
}

bool trafficlights::get_has_vehicle()
{
    return has_vehicle;
}

void trafficlights::acquire_target()
{

    QList<QGraphicsItem *> colliding_items = area->collidingItems();
    if(colliding_items.size()==1){
        has_vehicle = false;
        return;

    }
    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for(size_t i=0, n= colliding_items.size();i<n;i++){
        Vehicle * vehicle = dynamic_cast<Vehicle*>(colliding_items[i]);
        if(vehicle){ //if isnt vehicle type it will be a null ptr and will never execute
           double this_dist = distanceTo(vehicle);
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_vehicle = true;

        }
    }
   destination = closest_pt;
}


void trafficlights::traffic_light_timer()
{
    if(has_vehicle == false)
    {
        trafficLightOn = true;
        cross_road(1);
           //here I want to send a signal to every vehicle object in the are i specified informing them that the light is red
    }
    setPixmap(QPixmap(":/tlRed.png"));
    QTimer::singleShot(5000, this, SLOT(traffic_light_concurrency_timer()));

}

void trafficlights::traffic_light_concurrency_timer()
{
      trafficLightOn = false;
      pedestrianCount =0;
      setPixmap(QPixmap(":/tlGreen.png"));
      QTimer::singleShot(3000, this, SLOT(traffic_light_timer()));
}

void trafficlights::setUp()
{
    setPixmap(QPixmap(":/tlGreen.png"));
    trafficLightOn = false;
    QRectF rect(20,50,150,250);
    area = new QGraphicsRectItem(rect,this);
    area->setPen(QPen(Qt::DotLine));
    area->setPos(x()-30,y()+50);
}






