#include "pedestrianmaker.h"
#include "pedestrian.h"
#include "athlete.h"
#include "time.h"
pedestrianmaker::pedestrianmaker()
{

}

pedestrianmaker::~pedestrianmaker()
{

}

pedestrian *pedestrianmaker::makeRandomPedestrian()
{
    pedestrian *  ped = new pedestrian();
    int random_number = rand()%2;
    if(random_number == 0){
        ped = new athlete();
        return ped;
    }
    else{
       return ped;
    }

}