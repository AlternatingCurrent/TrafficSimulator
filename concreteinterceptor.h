#ifndef CONCRETEINTERCEPTOR_H
#define CONCRETEINTERCEPTOR_H
#include "contextobject.h"
#include <vector>

class ConcreteInterceptor
{
public:
    ConcreteInterceptor( std::vector <int*> s_Values);
    void event_callback(ContextObject *aContextObj);

private:
    std::vector <int*> speed_Values;
//signals:

//public slots:
};

#endif // CONCRETEINTERCEPTOR_H
