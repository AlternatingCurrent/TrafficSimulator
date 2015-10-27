#ifndef CONCRETEINTERCEPTOR_H
#define CONCRETEINTERCEPTOR_H
#include "loggingapp.h"
#include "contextobject.h"
#include <vector>

class ConcreteInterceptor
{
public:
    ConcreteInterceptor(std::vector <loggingInfo > &speed_time_values);
    void event_callback(ContextObject *aContextObj);

private:
    std::vector <loggingInfo > speed_Values;
//signals:

//public slots:
};

#endif // CONCRETEINTERCEPTOR_H
