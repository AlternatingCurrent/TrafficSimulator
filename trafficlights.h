#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QPoint>
#include <QObject>
#include <QString>
#include "subject.h"
class trafficlights: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    trafficlights(Subject *aVehicle, QGraphicsItem * parent =0);
    double distanceTo(QGraphicsItem * item);
    void cross_road(int pedestrianNo);
    bool trafficLightOn;
    bool getTrafficLightsState();
    bool get_has_vehicle();
    void setPosOfLights(int x, int y);
    int getPos(QString x);
public slots:
    void acquire_target();
    void traffic_light_timer();
    void traffic_light_concurrency_timer();
private:
    void setUp();
    int pedestrianCount;
    QGraphicsRectItem * area;
    QPointF destination;
    bool has_vehicle;
    int xPos;
    int yPos;
};

#endif // TRAFFICLIGHTS_H
