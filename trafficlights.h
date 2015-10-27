#ifndef TRAFFICLIGHTS_H
#define TRAFFICLIGHTS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QPoint>
#include <QObject>

class trafficlights: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    trafficlights(QGraphicsItem * parent =0);
    double distanceTo(QGraphicsItem * item);
    void cross_road(int pedestrianNo);
    bool trafficLightOn;
    bool getTrafficLightsState();
    bool get_has_vehicle();
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

};

#endif // TRAFFICLIGHTS_H
