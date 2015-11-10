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
     mState->addVehicle(*this,ui);
}

void MainWindow::on_btnStart_clicked()
{
  mState->startButtonClicked(*this,ui);
}

void MainWindow::on_btnStop_clicked()
{
     mState->stopSimulation(*this,ui);
}
void MainWindow::beginSimulation()
{
       mState->runSimulation(*this,ui);
}

void MainWindow::on_addVehicles_currentIndexChanged(const QString &arg1)
{
    ui->Aggressiveness->setVisible(true);
}

// State behaviour calls
void MainWindow::addRoad()
{
    mState->addRoad(*this,ui);
}

void MainWindow::addVehicle()
{

}

void MainWindow::runSimulation()
{
    mState->runSimulation(*this,ui);
}


void MainWindow::viewReport()
{
    mState->viewReport(*this,ui);
}

void MainWindow::addPedestrian(){
   mState->addPedestrain(*this,ui);
}


void MainWindow::trafficlightsCheck()
{
    if(lights->trafficLightOn == true){
      mState->addPedestrain(*this, ui);//Calls mehod in state

        return;
    }
    else{
        return;
    }
}

//Stop vehicles from accelerating too quickly
void MainWindow :: delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(100);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


//Move to factory maybe
void MainWindow::setUpCarImages(Vehicle * aVehicle){
    QPixmap watermark(":/carRedRight.png"); //changed
    QPixmap newPixmap = watermark.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    aVehicle->setPixmap(newPixmap);
    //QRectF rect(-70,-225,700,170);
    QRectF rect(0,-60,200,100);
    //create qgraphicsRectItem
    //this->boundingRect().setPen(QPen(Qt::white));
    aVehicle->area = new QGraphicsRectItem(rect,aVehicle);
    aVehicle-> area->setPen(QPen(Qt::white));
    aVehicle-> area->setPos(aVehicle->x()-30,aVehicle->y()+25);
    //this->boundingRect() = area;
   // area->hide();

}

