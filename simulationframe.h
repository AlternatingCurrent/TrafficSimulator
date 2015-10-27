#ifndef SIMULATIONFRAME_H
#define SIMULATIONFRAME_H
#include <QGraphicsView>
#include "trafficlights.h"

class SimulationFrame: public QGraphicsView{
Q_OBJECT
public:
        SimulationFrame();
        QGraphicsScene * scene;
        QTimer * spawnTimer;
        int vehicleSpawned; //for logging?
        trafficlights * lights;
        SimulationFrame getInstance();
private:
        static SimulationFrame simulation;


public slots:

};


#endif // SIMULATIONFRAME_H
