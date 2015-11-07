#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simulationframe.h"
#include "QGraphicsScene"
#include <QTimer>
#include <QPointF>
#include "qmath.h"
#include <QTransform>
#include <functional>
#include <iostream>
#include <time.h>
 #include <chrono>
#include <QDebug>
#include "pedestrian.h"
#include "pedestrianmaker.h"
#include <QTimer>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mState(new Setup()) //State behaviour, on start up state is set to Setup()
{
    ui->setupUi(this);
    asubject = new Subject();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnWeather_clicked()
{

}

void MainWindow::on_btnAddVehicle_clicked()
{
      string aggressiveness;
      string vehicleType;

      Subject * asubject = new Subject();
      QGraphicsItem * a;
      QGraphicsItem * b;
      QGraphicsItem * c;
      QGraphicsItem * d;
    //  Vehicle * aCar = new PoliceCar(asubject,50,50,3,a);

      Vehicle * car2 = new RegularCar(asubject,50,50,3,100,130, a);
      Vehicle * car1 = new RegularCar(asubject,50,50,1,100,300, b);                             //100,40 ->  top top
      Vehicle * car3 = new RegularCar(asubject,50,50,2,100,400, c);                             //100,130 -> top bottom
      Vehicle * car4 = new RegularCar(asubject,50,50,2,100,680, d);                             //100,300 -> middle top
                                                                                        //100,400 -> middle bottom
       scene->addItem(car2);                                                            //100,580 -> bottom top
//      scene->addItem(car1);                                                           //100,680 -> bottom bottom
//      scene->addItem(car3);
//      scene->addItem(car4);

//      car3->setPos(200, 400);
//      car1->setPos(200,400);
    // car2->setPos(100,60);
//      car3->setPos(200,400);
      aggressiveness = ui->Aggressiveness->currentText().toStdString();
      vehicleType    = ui->addVehicles->currentText().toStdString();


      vehicles.push_back(car2);
//      vehicles.push_back(car3);
//      vehicles.push_back(car1);
//      vehicles.push_back(car4);

}

void MainWindow::on_btnStart_clicked()
{
    //  asubject->notifyAllVehicles();
        start_stop = 1;

        while(start_stop){

        for(int i =0; i< vehicles.size();i++){
            vehicles.at(i)->update(vehicles);
          }
          delay();
          qApp->processEvents();
        }
}

void MainWindow::on_btnStop_clicked()
{
    start_stop =0;
}
void MainWindow::beginSimulation()
{
    setUp();
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(trafficlightsCheck()));
    timer->start(500);

     // QPixmap roadImage(":/Road.jpg");
        ui->Aggressiveness->setVisible(false);

        ui->addVehicles->addItem("Car");
        ui->addVehicles->addItem("Police Car");
        ui->addVehicles->addItem("Motorbike");

        ui->Aggressiveness->addItem("Low");
        ui->Aggressiveness->addItem("Medium");
        ui->Aggressiveness->addItem("High");

        lights = new trafficlights();
        lights->setPos(800,250);
        scene->addItem(lights);
//    addPedestrian(); //this will be cchanged to be called whenever lights are red

}

void MainWindow::on_addVehicles_currentIndexChanged(const QString &arg1)
{
    ui->Aggressiveness->setVisible(true);
}

void MainWindow::setUp()
{

    QPixmap watermark(":/Road.jpg");
    scene = new QGraphicsScene(0,0,1691,791);
    ui->mainSimulation->setScene(scene);
    ui->mainSimulation->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->mainSimulation->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setBackgroundBrush(QBrush(QImage(":/RoadSized.png")));
}

// State behaviour calls
void MainWindow::addRoad()
{
    mState->addRoad(*this);
}

void MainWindow::addVehicle()
{
    mState->addVehicle(*this);
}

void MainWindow::runSimulation()
{
    mState->runSimulation(*this);
}

void MainWindow::stopSimulation()
{
    mState->stopSimulation(*this);
}

void MainWindow::viewReport()
{
    mState->viewReport(*this);
}

void MainWindow::addPedestrian(){
    pedestrianmaker * pedmaker = new pedestrianmaker();
    pedestrian  * ped ;
    ped =pedmaker->makeRandomPedestrian();
    scene->addItem(ped);
    int posOfXLights = lights->x() + 20;
    ped->setPos(posOfXLights,lights->y()+ped->getSpeed());
    while(ped->y() < ped->getMaxRange()){
             ped->setPos(posOfXLights,ped->y()+20);
             delay();
             qApp->processEvents();
           }
 delete ped;
}


void MainWindow::trafficlightsCheck()
{
    if(lights->trafficLightOn == true){
        addPedestrian();
        return;
    }
    else{
        return;
    }
}

//Stop vehicles from accelerating too quickly
void MainWindow :: delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(75);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

