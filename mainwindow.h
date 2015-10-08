#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
