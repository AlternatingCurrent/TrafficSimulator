#ifndef CONTEXTOBJECT_H
#define CONTEXTOBJECT_H
#include "vehicle.h"


class ContextObject
{
    friend class vehicle;
public:
    ContextObject(int s);
    int get_Value();

private:
    int speed;
//signals:

//public slots:
};

#endif // CONTEXTOBJECT_H
