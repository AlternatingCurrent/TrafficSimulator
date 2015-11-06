#include "vehicle.h";
#include "regularcar.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "qmath.h"
#include <typeinfo>
#include <QDebug>
#include <iostream>
#include <QPen>

RegularCar::RegularCar(Subject *aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos, QGraphicsItem *parent):Vehicle(width,height,aggression,xStartingPos,yStartingPos)
{
  qDebug()<< xStartingPos;
  setPos(xStartingPos, yStartingPos);
  setUp();
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void RegularCar::update(vector<Vehicle *> vehicles){ //Maybe only pass in vehicles that are in its scope

  //Setting up the interchangable strategy context object
  if(aggression ==  High){
  StrategyContext * context = new StrategyContext(new IncreaseSpeedAggressive());
  context->executeStrategyDecision(vehicles, this);
  context = new StrategyContext(new DecreaseSpeed());
  context->executeStrategyDecision(vehicles, this);
  context = new StrategyContext(new OvertakeHigh());
  context->executeStrategyDecision(vehicles, this);
  }
  if(aggression == Medium){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedMedium());
    context->executeStrategyDecision(vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(vehicles, this);
    context = new StrategyContext(new OverTakeMedium());
    context->executeStrategyDecision(vehicles, this);
  }
  if(aggression == Low){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedLow());
    context->executeStrategyDecision(vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(vehicles, this);
  }

  //Call Methods
}


void RegularCar::setUp()
{
        QPixmap watermark(":/carRedRight.png"); //changed
        QPixmap newPixmap = watermark.scaled(QSize(50,50),  Qt::KeepAspectRatio);
        setPixmap(newPixmap);
        QRectF rect(-70,-225,700,170);
        //create qgraphicsRectItem
        //this->boundingRect().setPen(QPen(Qt::white));
        area = new QGraphicsRectItem(rect,this);
        area->setPen(QPen(Qt::white));
        area->setPos(x()-30,y()+25);
        //this->boundingRect() = area;
       // area->hide();
}




