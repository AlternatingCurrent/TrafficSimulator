#ifndef LOGGINGAPP_H
#define LOGGINGAPP_H
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include "concreteinterceptor.h"
#include "dispatcher.h"



class LoggingApp
{
public:
    LoggingApp();
    void createInterceptor();
    void updateTextFile();
    ConcreteInterceptor getInterceptor();

//private:
    ConcreteInterceptor cInterceptor;
    std::vector <loggingInfo > speed_time_values;

//signals:

//public slots:
};

#endif // LOGGINGAPP_H
