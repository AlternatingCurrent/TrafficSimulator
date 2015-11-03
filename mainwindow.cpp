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

 //  aCar->speedUp();
  // car2->speedUp();
 // QPixmap carLeft(":/carRedLeft.png");
 // QLabel *label = new QLabel(this);
 // label->setScaledContents(true);
 // label->setPixmap(carLeft);
  //label->setParent(ui->mainDisplay);
  //label->setGeometry(0,0,110,270);
  //label->show();


  Subject * asubject = new Subject();
  QGraphicsItem * a;

  Vehicle * aCar = new PoliceCar(asubject,50,50,3,a);

  Vehicle * car2 = new RegularCar(asubject,50,50,3, a);
  scene->addItem(car2);

  aggressiveness = ui->Aggressiveness->currentText().toStdString();
  vehicleType    = ui->addVehicles->currentText().toStdString();

  cout << aggressiveness << "\n" << vehicleType;

  //vehicles.push_back(car2);

}

void MainWindow::on_btnStart_clicked()
{
   // asubject->notifyAllVehicles();
    //for(int i =0; i< vehicles.size();i++){
        //vehicles.at(i)->update(vehicles);
   // }
}

void MainWindow::on_btnStop_clicked()
{

}
void MainWindow::beginSimulation()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(trafficlightsCheck()));
    timer->start(500);

    QPixmap roadImage(":/Road.jpg");
    ui->mainDisplay->setScaledContents(true);
    ui->mainDisplay->setPixmap(roadImage);
    ui->Aggressiveness->setVisible(false);

    ui->addVehicles->addItem("Car");
    ui->addVehicles->addItem("Police Car");
    ui->addVehicles->addItem("Motorbike");

    ui->Aggressiveness->addItem("Low");
    ui->Aggressiveness->addItem("Medium");
    ui->Aggressiveness->addItem("High");

    QPixmap watermark(":/Road.jpg");
    QPixmap newPixmap = watermark.scaled(QSize(800,600),  Qt::KeepAspectRatio);
    scene = new QGraphicsScene(this);
    ui->mainSimulation->setScene(scene);
    scene->setBackgroundBrush(QBrush(newPixmap));
    lights = new trafficlights();
    lights->setPos(800,250);
    lights->setPosOfLights(800,250);
    scene->addItem(lights);
//    addPedestrian(); //this will be cchanged to be called whenever lights are red

}

void MainWindow::on_addVehicles_currentIndexChanged(const QString &arg1)
{
    ui->Aggressiveness->setVisible(true);
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
    ped->setPos(lights->getPos("x")+20,lights->getPos("y") +60);
    scene->addItem(ped);
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
