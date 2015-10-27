#include "contextobject.h"


ContextObject::ContextObject(int s)
{
    speed = s;
}

int ContextObject::get_Value()
{
    return speed;
}
