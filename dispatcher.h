#ifndef DISPATCHER_H
#define DISPATCHER_H
#include "concreteinterceptor.h"
#include "contextobject.h"

class Dispatcher
{
public:
    Dispatcher();
    void attach(ConcreteInterceptor *anInterceptor);
    void callback(ContextObject *aContextObj);

private:
    //STD if not using std
    std::vector <ConcreteInterceptor *> interceptors;


//signals:

//public slots:
};

#endif // DISPATCHER_H
