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
  // Colin changed for debugging setPos(xStartingPos, yStartingPos);
  //setUp();
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

//Thread setup , correct way to do it, QT documentation is incorrect in subclassing from QThread
//i.e. QObject and move this object to qthread in main states
void RegularCar::DoThreadSetup(QThread &cThread, vector <Vehicle*> vehicles){
    //connect the signal emitted from the thread "starting" to the slot update
    this->vehicles = vehicles;
    connect(&cThread,SIGNAL(started()),this,SLOT(update()));
}

//Update no longer accepts vehicles as they are now threads, and you cannot
//pass data through this siganl and slot therefore we make a copy in do thread setup

void RegularCar::update(){ //Maybe only pass in vehicles that are in its scope

    //Only execute the following when the thread status is active
  while(this->getThreadStatus() == true){

  //Sleep thread for 100 ms every iteration
  QThread::currentThread()->msleep(100);

  //Setting up the interchangable strategy context object
  if(aggression ==  High){
  StrategyContext * context = new StrategyContext(new IncreaseSpeedAggressive());
  context->executeStrategyDecision(this->vehicles, this);
  context = new StrategyContext(new DecreaseSpeed());
  context->executeStrategyDecision(this->vehicles, this);
  context = new StrategyContext(new OvertakeHigh());
  context->executeStrategyDecision(this->vehicles, this);
  }

  if(aggression == Medium){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedMedium());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new OverTakeMedium());
    context->executeStrategyDecision(this->vehicles, this);
  }

  if(aggression == Low){
    StrategyContext * context = new StrategyContext(new IncreaseSpeedLow());
    context->executeStrategyDecision(this->vehicles, this);
    context = new StrategyContext(new DecreaseSpeed());
    context->executeStrategyDecision(this->vehicles, this);
  }
 }

}

void RegularCar::setUp()
{
        QPixmap watermark(":/carRedRight.png"); //changed
        QPixmap newPixmap = watermark.scaled(QSize(50,50),  Qt::KeepAspectRatio);
        setPixmap(newPixmap);
        //QRectF rect(-70,-225,700,170);
        QRectF rect(0,-60,200,100);
        //create qgraphicsRectItem
        //this->boundingRect().setPen(QPen(Qt::white));
        area = new QGraphicsRectItem(rect,this);
        area->setPen(QPen(Qt::white));
        area->setPos(x()-30,y()+25);
        //this->boundingRect() = area;
       // area->hide();
}


