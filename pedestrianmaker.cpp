#include "pedestrianmaker.h"
#include "pedestrian.h"
#include "regularpedestrian.h"
#include "babypedestrian.h"
#include "babypedestrianadapter.h"
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
    pedestrian *  ped = new RegularPedestrian();
    int random_number = rand()%3;
    if(random_number == 0){
        ped = new athlete();
        return ped;
    }else if(random_number == 1 ){
        BabyPedestrian *baby = new BabyPedestrian();
        ped = new BabyPedestrianAdapter(baby);
        return ped;
    }
    else{
       return ped;
    }

}
