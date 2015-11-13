#include "dispatcher.h"
#include <stdio.h>

using namespace std;

Dispatcher::Dispatcher()
{

}


void Dispatcher::attach(ConcreteInterceptor *anInterceptor){
   interceptors.push_back(anInterceptor);
}

void Dispatcher::callback(ContextObject *aContextObj ){
  for(unsigned i =0; i< interceptors.size();i++){
      interceptors.at(i)->event_callback(aContextObj);   //Same as event_callback()
    }
}
