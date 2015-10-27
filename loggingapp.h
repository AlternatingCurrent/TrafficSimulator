#ifndef LOGGINGAPP_H
#define LOGGINGAPP_H
#include <ctime>
#include <vector>

struct loggingInfo {
    time_t time;
    int speed;
};

class LoggingApp
{
public:
    LoggingApp();
    void createInterceptor();
    void updateTextFile();


private:
    std::vector <loggingInfo > speed_time_values;

//signals:

//public slots:
};

#endif // LOGGINGAPP_H
