#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subject.h"
#include "QGraphicsScene"
#include "trafficlights.h"
#include "pedestrian.h"
#include "vehicle.h"
#include <QTimer>
#include <QPointF>
#include "qmath.h"
#include <QTransform>
#include <functional>
#include <iostream>
#include <time.h>
 #include <chrono>
#include <QDebug>
#include <vector>
#include <QtGui>
#include <iostream>
#include <string>

#include "policecar.h"
#include "regularcar.h"
#include "subject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void beginSimulation();

private slots:

    void on_btnWeather_clicked();

    void on_btnAddVehicle_clicked();

    void on_btnStart_clicked();

    void on_btnStop_clicked();



    void on_addVehicles_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Subject * asubject;
    trafficlights * lights;
    QGraphicsScene *scene;
    std::vector<Vehicle*> vehicles;
};

#endif // MAINWINDOW_H
