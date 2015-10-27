#include "concreteinterceptor.h"

ConcreteInterceptor::ConcreteInterceptor(std::vector <loggingInfo > &speed_time_values)
{
    speed_Values = speed_time_values;
}


void ConcreteInterceptor::event_callback(ContextObject *aContextObj){
    loggingInfo x;
    x.speed = aContextObj->get_Value();
    time(&x.time);
    speed_Values.push_back(x);

}
