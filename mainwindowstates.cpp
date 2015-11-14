#include "mainwindowstates.h"
#include <iostream>
#include "vehiclefactory.h"
using namespace std;


//Make get's and set
Subject * asubject = new Subject();
bool start_stop =0;
trafficlights * lights;
QGraphicsScene *scene;
QGraphicsView * view;
std::vector<Vehicle*> vehicles;
int maxNumberOfCars =0;


QVector<QThread*> vehicleThreads;

QThread aThread;
QThread bThread;
QThread cThread;
QThread dThread;
QThread eThread;
QThread fThread;
QThread gThread;


bool TrafficLightsStop;


//Interceptor
LoggingApp logger = LoggingApp();

AbstractState::~AbstractState()
{
}

void AbstractState::setState(MainWindow &mWindow, AbstractState *state)
{
    AbstractState *aux = mWindow.mState;
    mWindow.mState = state;
    delete aux;
}

Setup::~Setup()
{
    logger.createInterceptor();
}

void Setup::addRoad(MainWindow &mWindow,Ui::MainWindow * ui)
{
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "Road\n");
}

void Setup::addVehicle(MainWindow &mWindow,Ui::MainWindow * ui)
{
     int carx;
     int cary;
     string direction;

      maxNumberOfCars++;
      if(maxNumberOfCars <=7){
      if(maxNumberOfCars == 1){
      vehicleThreads.push_back(&aThread);
      carx = 0;
      cary = 450;
      direction = "east";

      }
      if(maxNumberOfCars == 2){
      vehicleThreads.push_back(&bThread);
      carx = 200;
      cary = 450;
      direction = "east";
      }
      if(maxNumberOfCars == 3){
      vehicleThreads.push_back(&cThread);
      carx = 300;
      cary = 450;
      direction = "east";
      }
      if(maxNumberOfCars == 4){
      vehicleThreads.push_back(&dThread);
      carx = 1000;
      cary = 550;
      direction = "west";
      }

      //*************** scenario 1 on top overtaking example
      if(maxNumberOfCars == 5){
      vehicleThreads.push_back(&eThread);
      carx = 0;
      cary = 80;
      direction = "east";
      }
      if(maxNumberOfCars == 6){
      vehicleThreads.push_back(&fThread);
      carx = 200;
      cary = 80;
      direction = "east";
      }
      if(maxNumberOfCars == 7){
      vehicleThreads.push_back(&gThread);
      carx = 500;
      cary = 170;
      direction = "west";
      }





      //***************

       string aggressiveness;
       QString vehicleType;
       vehicleType    = ui->addVehicles->currentText().toStdString().c_str();;
      aggressiveness = ui->Aggressiveness->currentText().toStdString();
      Vehicle * carTry;
      VehicleFactory * vf = new VehicleFactory();
      carTry = vf->createVehicle(vehicleType/*"carwithtrailer"*/,aggressiveness,carx,cary,asubject,scene,direction);
      scene->addItem(carTry);


     // vehicleType    = ui->addVehicles->currentText().toStdString();
      vehicles.push_back(carTry);

      //Interceptor

      carTry->createDispatcher();
      carTry->dis.attach(logger.getInterceptor());

    }else{
       ui->reportBox->setText("You can only add maxium of four vehicles");
      }




      //Can no longer set up the images and rectangles from Vehicle as the threads all cannot concurrently access
      //the ui, only the main thread, and makes less sense to use emitting frtom vehcile over setyp in Mainwindw




//      mWindow.setUpCarImages(car1);
//      mWindow.setUpCarImages(car2);
//      mWindow.setUpCarImages(car3);
//      mWindow.setUpCarImages(car4);



//      scene->addItem(car2);
//      scene->addItem(car1);
//      scene->addItem(car3);
//      scene->addItem(car4);



//      car3->setPos(1000, 400);
//      car1->setPos(150,450);
//      car2->setPos(0,450);
//      car3->setPos(100,450);

//      vehicles.push_back(car2);
//      vehicles.push_back(car3);
//      vehicles.push_back(car1);
//      vehicles.push_back(car4);

}

void Setup::runSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // code to run simulation and change to simulation state
    std::cout<< "Running simulation " << std::endl;


//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(trafficlightsCheck()));
//    timer->start(500);

    QPixmap roadImage(":/Road.jpg");
        ui->Aggressiveness->setVisible(false);
        ui->addVehicles->addItem("regularcar");
        ui->addVehicles->addItem("carwithtrailer");
        ui->addVehicles->addItem("policecar");

        ui->Aggressiveness->addItem("Low");
        ui->Aggressiveness->addItem("Medium");
        ui->Aggressiveness->addItem("High");

        QPixmap watermark(":/road_new.png");
        QPixmap newPixmap = watermark.scaled(QSize(800,600),  Qt::KeepAspectRatio);

        Subject * aVehicle = new Subject();
        scene = new QGraphicsScene();
        ui->mainSimulation->setScene(scene);
        scene->setBackgroundBrush(QBrush(QImage(":/road_new.png")/*QBrush(newPixmap)*/));
        lights = new trafficlights(aVehicle );
        lights->setPos(800,/*-100*/250);
         scene->addItem(lights);

}

void Setup::startButtonClicked(MainWindow &mWindow, Ui::MainWindow *ui){
    setState(mWindow, new Simulation());
}

void Setup::addPedestrain(MainWindow &mWindow, Ui::MainWindow *ui){

}

void Setup::stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation is not running, nothing to stop
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation not running, nothing to stop\n");

}
void Setup::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation has not run yet, nothing to show
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation has not run, nothing to show\n");
}

Simulation::~Simulation()
{
}

void Simulation::addRoad(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation already running
}
void Simulation::addVehicle(MainWindow &mWindow,Ui::MainWindow * ui)
{
    //throw error, Simulation already running
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation already running\n");
}
void Simulation::runSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    //throw error, Simulation already running
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation already running\n");
}
void Simulation::stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
     TrafficLightsStop = true;
    // code to stop simulation here
    start_stop = 0;
    cout << "Stop Simulation\n";
//    int totalTimesCalled = 0;

    //Turn off all threads
    for(unsigned i =0; i< vehicles.size();i++){
//        totalTimesCalled += vehicles.at(i)->timesCalled;
        vehicles.at(i)->setThreadStatus(false);
    }
    // Interceptor code, should be moved to report::viewReport
    logger.updateTextFile();
// Performance checking, comment out at release
//    cout << "Total times vehicals have been called: " << totalTimesCalled << "\n";
    setState(mWindow, new ReportState());

}
void Simulation::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation is running, stop simulation first
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation running, stop simulation first\n");
}

void Simulation::addPedestrain(MainWindow &mWindow, Ui::MainWindow *ui){
    //qDebug()<< "in add ped";
    pedestrianmaker * pedmaker = new pedestrianmaker();
    pedestrian  * ped ;
    ped =pedmaker->makeRandomPedestrian(scene);
    scene->addItem(ped);
    ped->move2(lights->x(), lights->y());
}

void Simulation :: startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui ){
    start_stop = 1;
     TrafficLightsStop == false;
    cout << "Simulation in Class Simulation";


    //**************************SETUP THREAD********************************************************************
    for(unsigned i =0; i< vehicles.size();i++){
            //vehicles now have access to lights to check if it sees them :)
            vehicles.at(i)->DoThreadSetup(*vehicleThreads.at(i),vehicles,lights);
            vehicles.at(i)->moveToThread(vehicleThreads.at(i)); //Take this objet and move it into &cThread, not suclassign the thre, instead we are moving it to the thread
            connect(vehicles.at(i), SIGNAL(dispatchNewVehiclePositions(Vehicle*,int,int)), this ,
                    SLOT(recieveNewVehiclePositions(Vehicle*,int,int)));
      }
     //*****************************************************************************************************************

    //start all the threads
    for(unsigned i =0; i< vehicles.size();i++){
    vehicles.at(i)->setThreadStatus(true); //Set status to true therefore thread will last until staus is set to false
    vehicleThreads.at(i)->start();
    }

//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(trafficlightsCheck()));
//    timer->start(50);

    while(TrafficLightsStop == false){
        //qDebug()<< "trafficlights boolean "<<TrafficLightsStop;
        trafficLightsCheck();
        mWindow.delay();
        qApp->processEvents();

    }
    //***************************OLD WAY****************************

   // while(start_stop){
   //  for(int i =0; i< vehicles.size();i++){
   //      vehicles.at(i)->DoThreadSetup(aThread,vehicles);
   //      vehicles.at(i)->update();
   //   }
   //   mWindow.delay();
   //   qApp->processEvents();
   // }


}

void Simulation::recieveNewVehiclePositions(Vehicle *currentVehicle, int x, int y){
  //cout << x  <<"   " << y << "\n";
  currentVehicle->setPos(x,y);
}

void Simulation::trafficLightsCheck()
{
    if(lights->trafficLightOn == true){
       asubject->setState(1);
       // qDebug()<< "in add ped";
        pedestrianmaker * pedmaker = new pedestrianmaker();
        pedestrian  * ped ;
        ped =pedmaker->makeRandomPedestrian(scene);
        scene->addItem(ped);
        ped->move2(lights->x(), lights->y());
        return;
    }
    else{
        asubject->setState(0); //trafficlight is off
        return;
    }
}

ReportState::~ReportState()
{
}

void ReportState::addRoad(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // display message that state is being changed to Setup, press the add road button again
    setState(mWindow, new Setup());
}
void ReportState::addVehicle(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // display message that state is being changed to Setup, press the add road button again
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "Moving to Setup state\n");
    setState(mWindow, new Setup());
}
void ReportState::runSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // message, Running simulation with same roards and cars
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "Moving to Simulation state\n");
    setState(mWindow, new Simulation());

}
void ReportState::stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation not running
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "ERROR: Simulation not running\n");

}
void ReportState::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // code to show report goes here
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "Report: Simulation Finished, Logs can be found in the logs.txt file\n");
}

void ReportState::addPedestrain(MainWindow &mWindow, Ui::MainWindow *ui){

}

void ReportState :: startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui ){
    ui->reportBox->setText(ui->reportBox->document()->toPlainText() + "Moving to Simulation state\n");
    setState(mWindow, new Simulation());
}

