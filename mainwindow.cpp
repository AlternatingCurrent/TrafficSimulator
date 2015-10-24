#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>
#include <string>
#include "subject.h"
#include "vehicle.h"
#include "policecar.h"
#include "regularcar.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
  int aggressiveness;

  Vehicle * aCar = new PoliceCar(asubject,50,50,2);
  Vehicle * car2 = new RegularCar(asubject,50,50,1);

 //  aCar->speedUp();
  // car2->speedUp();

}

void MainWindow::on_btnStart_clicked()
{
    asubject->notifyAllVehicles();
}

void MainWindow::on_btnStop_clicked()
{

}
void MainWindow::beginSimulation()
{
    QPixmap roadImage(":/Road.jpg");
    ui->mainDisplay->setScaledContents(true);
    ui->mainDisplay->setPixmap(roadImage);
    ui->Agressiveness->setVisible(false);
}

void MainWindow::on_addVehicles_currentIndexChanged(const QString &arg1)
{
    ui->Agressiveness->setVisible(true);
}
