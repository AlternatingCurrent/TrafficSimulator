#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
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
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "policecar.h"
#include "regularcar.h"
#include "subject.h"
#include "mainwindowstates.h"
#include <QObject>
#include <QPen>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class AbstractState;

class MainWindow : public QMainWindow
{
    friend class AbstractState;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void beginSimulation();
    // State behaviour
    void addRoad();
    void addVehicle();
    void runSimulation();
    void stopSimulation();
    void viewReport();
    void addPedestrian();
    void delay();
    void setUpCarImages(Vehicle * aVehicle);

public slots:
    void trafficlightsCheck();
private slots:

    void on_btnAddVehicle_clicked();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_addVehicles_currentIndexChanged(const QString &arg1);

    void on_btnViewReport_clicked();

private:
    Subject * asubject;
    trafficlights * lights;
    Ui::MainWindow *ui;
    static MainWindow mainwindow;
    // State behaviour
    AbstractState *mState;

    QGraphicsRectItem * area;

};

#endif // MAINWINDOW_H
