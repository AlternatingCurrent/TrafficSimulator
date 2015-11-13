#ifndef CONCRETEINTERCEPTOR_H
#define CONCRETEINTERCEPTOR_H
#include "contextobject.h"
#include <time.h>
#include <vector>
#include <iostream>

struct loggingInfo {
    time_t time;
    int speed;
};

class ConcreteInterceptor
{
public:
    ConcreteInterceptor();
    ConcreteInterceptor(std::vector <loggingInfo > *speed_time_values);
    void event_callback(ContextObject *aContextObj);

private:
    std::vector <loggingInfo > *speed_Values;
//signals:

//public slots:
};

#endif // CONCRETEINTERCEPTOR_H
