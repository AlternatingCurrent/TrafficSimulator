#include "policecar.h"
#include <QGraphicsPixmapItem>

PoliceCar::PoliceCar(Subject * aVehicle, int width, int height, double aggression, int xStartingPos, int yStartingPos, QGraphicsItem *parent):Vehicle(width,height,aggression, xStartingPos, yStartingPos)
{
    setPos(xStartingPos, yStartingPos);
 //   setUp();
// this->topSpeed = 120; //REVIEW WITH AARON AND JUAN, WILL WE ADD IT AS A PARAMETER OR HAVE IT SET
 this->aVehicle = aVehicle;
 this->aVehicle->attach(this);
}

void PoliceCar::update(){
   std::cout << "PoliceCar Scan Ahead";
   //Does all the checks from vehicle
   //When somebody is speeding we can just add a method call
   //when the interceptor logs this
}

void PoliceCar::setUp()
{

    QPixmap watermark(":/policeCar.png");
    QPixmap newPixmap = watermark.scaled(QSize(100,100),  Qt::KeepAspectRatio);
    setPixmap(newPixmap);
    QRectF rect(-70,-225,700,170);
    area = new QGraphicsRectItem(rect,this);
   // area->setPen(QPen(Qt::white));
    area->setPos(x()-30,y()+50);
    area->hide();
}

//Thread setup , correct way to do it, QT documentation is incorrect in subclassing from QThread
void PoliceCar::DoThreadSetup(QThread &cThread, vector <Vehicle*> vehicles){
    //connect the signal emitted from the thread starting to the slot update
    this->vehicles = vehicles;
    connect(&cThread,SIGNAL(started()),this,SLOT(update(vehicles)));
}
