#include "regularcar.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "vehicle.h";
#include "qmath.h"
#include <typeinfo>
#include <QDebug>
#include <iostream>
RegularCar::RegularCar(Subject *aVehicle, int width, int height, double aggression, QGraphicsItem *parent):Vehicle(width,height,aggression)
{
  setUp();
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void RegularCar::update(){
  std::cout << "regular car scan ahead";

  //Call Methods
}


void RegularCar::setUp()
{
        QPixmap watermark(":/car.png"); //changed
        QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
        setPixmap(newPixmap);
        QRectF rect(0,-60,200,100);
        //create qgraphicsRectItem
        area = new QGraphicsRectItem(rect,this);
       // area->setPen(QPen(Qt::white));
        area->setPos(x()-30,y()+50);
        area->hide();
}

