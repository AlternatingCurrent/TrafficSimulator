#include <iostream>
#include "loggingapp.h"

LoggingApp::LoggingApp()
{

}

void LoggingApp::createInterceptor()
{
    cInterceptor = ConcreteInterceptor(&speed_time_values);
}

void LoggingApp::updateTextFile()
{
    std::ofstream loggingFile("logs.txt");
    if(loggingFile.is_open()) {
        for(int i =0; i < speed_time_values.size(); i++){
            loggingFile << speed_time_values[i].time;
            loggingFile << "," << speed_time_values[i].speed;
            loggingFile << "\n";
        }
    } else
        std::cout << "Unable to open file\n";

}
