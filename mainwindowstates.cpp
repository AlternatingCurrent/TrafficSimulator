#include "mainwindowstates.h"
#include <iostream>
#include "vehiclefactory.h"
using namespace std;


//Make get's and set
bool start_stop =0;
trafficlights * lights;
QGraphicsScene *scene;
QGraphicsView * view;
std::vector<Vehicle*> vehicles;

QVector<QThread*> vehicleThreads;

QThread aThread;
QThread bThread;
QThread cThread;
QThread dThread;
bool TrafficLightsStop;
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
}

void Setup::addRoad(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // code to add road here
}

void Setup::addVehicle(MainWindow &mWindow,Ui::MainWindow * ui)
{

     vehicleThreads.push_back(&aThread);
//     vehicleThreads.push_back(&bThread);
//     vehicleThreads.push_back(&cThread);
//     vehicleThreads.push_back(&dThread);

    string aggressiveness;
    string vehicleType;

      Subject * asubject = new Subject();
//      QGraphicsItem * a;
//      QGraphicsItem * b;
//      QGraphicsItem * c;
//      QGraphicsItem * d;
    //  Vehicle * aCar = new PoliceCar(asubject,50,50,3,a);

//      Vehicle * car2 = new RegularCar(asubject,50,50,3,100,450);
//      Vehicle * car1 = new RegularCar(asubject,50,50,1,150,450);
//      Vehicle * car3 = new RegularCar(asubject,50,50,2,0,450);
//      Vehicle * car4 = new RegularCar(asubject,50,50,2,1000,450);
      Vehicle * carTry;
      VehicleFactory * vf = new VehicleFactory();
      carTry = vf->createVehicle("regularcar",1,100,450,asubject);
      scene->addItem(carTry);








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

      aggressiveness = ui->Aggressiveness->currentText().toStdString();
      vehicleType    = ui->addVehicles->currentText().toStdString();

vehicles.push_back(carTry);
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
        ui->addVehicles->addItem("Car");
        ui->addVehicles->addItem("Police Car");
        ui->addVehicles->addItem("Motorbike");

        ui->Aggressiveness->addItem("Low");
        ui->Aggressiveness->addItem("Medium");
        ui->Aggressiveness->addItem("High");

        QPixmap watermark(":/Road.jpg");
        QPixmap newPixmap = watermark.scaled(QSize(800,600),  Qt::KeepAspectRatio);
        Subject * aVehicle = new Subject();
        scene = new QGraphicsScene();
        ui->mainSimulation->setScene(scene);
        scene->setBackgroundBrush(QBrush(newPixmap));
        lights = new trafficlights(aVehicle );
        lights->setPos(800,250);
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

}
void Setup::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation has not run yet, nothing to show
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
}
void Simulation::runSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    //throw error, Simulation already running
}
void Simulation::stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
     TrafficLightsStop = true;
    // code to stop simulation here
    start_stop = 0;
    cout << "Stop Simulation";

    //Turn off all threads
    for(int i =0; i< vehicles.size();i++){
    vehicles.at(i)->setThreadStatus(false);
    }

    setState(mWindow,new ReportState());


}
void Simulation::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation is running, stop simulation first
}

void Simulation::addPedestrain(MainWindow &mWindow, Ui::MainWindow *ui){
    qDebug()<< "in add ped";
    pedestrianmaker * pedmaker = new pedestrianmaker();
    pedestrian  * ped ;
    ped =pedmaker->makeRandomPedestrian();
    scene->addItem(ped);
    ped->move2(lights->x(), lights->y());
}

void Simulation :: startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui ){
    start_stop = 1;
     TrafficLightsStop == false;
    cout << "Simulation in Class Simulation";


    //**************************SETUP THREAD********************************************************************
    for(int i =0; i< vehicles.size();i++){

            vehicles.at(i)->DoThreadSetup(*vehicleThreads.at(i),vehicles);
            vehicles.at(i)->moveToThread(vehicleThreads.at(i)); //Take this objet and move it into &cThread, not suclassign the thre, instead we are moving it to the thread
            connect(vehicles.at(i), SIGNAL(dispatchNewVehiclePositions(Vehicle*,int,int)), this ,
                    SLOT(recieveNewVehiclePositions(Vehicle*,int,int)));
      }
     //*****************************************************************************************************************


    //start all the threads
    for(int i =0; i< vehicles.size();i++){
    vehicles.at(i)->setThreadStatus(true); //Set status to true therefore thread will last until staus is set to false
    vehicleThreads.at(i)->start();
    }

//    QTimer * timer = new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(trafficlightsCheck()));
//    timer->start(50);

    while(TrafficLightsStop == false){
        qDebug()<< "trafficlights boolean "<<TrafficLightsStop;
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
  cout << x  <<"   " << y << "\n";
  currentVehicle->setPos(x,y);
}

void Simulation::trafficLightsCheck()
{
    if(lights->trafficLightOn == true){
        qDebug()<< "in add ped";
        pedestrianmaker * pedmaker = new pedestrianmaker();
        pedestrian  * ped ;
        ped =pedmaker->makeRandomPedestrian();
        scene->addItem(ped);
        ped->move2(lights->x(), lights->y());
        return;
    }
    else{
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
    setState(mWindow, new Setup());
}
void ReportState::runSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // message, Running simulation with same roards and cars
    setState(mWindow, new Simulation());

}
void ReportState::stopSimulation(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // throw error, Simulation not running

}
void ReportState::viewReport(MainWindow &mWindow,Ui::MainWindow * ui)
{
    // code to show report goes here
}

void ReportState::addPedestrain(MainWindow &mWindow, Ui::MainWindow *ui){

}

void ReportState :: startButtonClicked(MainWindow &mWindow,Ui::MainWindow * ui ){

}

