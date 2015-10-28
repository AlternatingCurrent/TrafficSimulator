#include "carwithtrailer.h"
#include "vehicle.h"
#include "subject.h"
carwithtrailer::carwithtrailer(Subject *aVehicle, int width, int height, double aggression, QGraphicsItem *parent):Vehicle(width,height,aggression)
{
    setUp();
  //this->topSpeed = 100;
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
}

void carwithtrailer::update(){
  std::cout << "regular car scan ahead";

  //Call Methods
}
void carwithtrailer::setUp()
{
    QPixmap watermark(":/cartrailer.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    QRectF rect(0,-60,150,100);
    area = new QGraphicsRectItem(rect,this);
   // area->setPen(QPen(Qt::white));
    area->setPos(x()-30,y()+50);
}
