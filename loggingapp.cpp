#include <iostream>
#include "loggingapp.h"
#include <time.h>       /* time_t, struct tm, time, localtime, asctime */

LoggingApp::LoggingApp()
{

}

void LoggingApp::createInterceptor()
{
    cInterceptor = ConcreteInterceptor(&speed_time_values);
}

ConcreteInterceptor *LoggingApp::getInterceptor()
{
    return &cInterceptor;
}

void LoggingApp::updateTextFile()
{
    struct tm * timeinfo;
    std::ofstream loggingFile("logs.txt");
    if(loggingFile.is_open()) {
        for(int i =0; i < speed_time_values.size(); i++){
            timeinfo = localtime ( &speed_time_values[i].time );
            loggingFile << asctime (timeinfo);
            loggingFile << "," << speed_time_values[i].speed;
            loggingFile << "\n";
        }
    } else
        std::cout << "Unable to open file\n";

}
