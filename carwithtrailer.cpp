#include "carwithtrailer.h"
#include "vehicle.h"
#include "subject.h"
carwithtrailer::carwithtrailer(Subject *aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos, QGraphicsItem *parent):Vehicle(width,height,aggression, xStartingPos, yStartingPos)
{

  //this->topSpeed = 100;
  setPos(xStartingPos, yStartingPos);
  this->aVehicle = aVehicle;
  this->aVehicle->attach(this);
  setUp();
}

void carwithtrailer::update(vector<Vehicle *> vehicles){
  std::cout << "regular car scan ahead";

  //Call Methods
}
void carwithtrailer::setUp()
{
    QPixmap watermark(":/cartrailer.png");
    QPixmap newPixmap = watermark.scaled(QSize(150,150),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    QRectF rect(-70,-225,700,170);
    area = new QGraphicsRectItem(rect,this);
   // area->setPen(QPen(Qt::white));
    area->setPos(x()-30,y()+50);
}
