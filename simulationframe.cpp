#include "simulationframe.h"
#include "QGraphicsScene"
#include "trafficlights.h"
#include "pedestrian.h"
#include "vehicle.h"
#include <QTimer>
#include <QPointF>
#include "qmath.h"
#include <QTransform>
#include <functional>
#include <iostream>
#include <time.h>
 #include <chrono>
#include <QDebug>
using namespace std;
SimulationFrame::SimulationFrame()
{


    scene = new QGraphicsScene(0,0,0,0);  //sizes are all wrong yet to be decide.....
    setScene(scene);
    QPixmap watermark(":/Road.jpg");
    QPixmap newPixmap = watermark.scaled(QSize(800,600),  Qt::KeepAspectRatio);
    setBackgroundBrush(QBrush(newPixmap));
    lights = new trafficlights();
    lights->setPos(800,250);
    scene->addItem(lights);
    vehicleSpawned =0;
    setFixedSize(800,300);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  //setStyleSheet("border-width: 0px; border-style: solid");
   //setContentsMargins(QMargins());

}






