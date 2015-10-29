#include "strategycontext.h"


    StrategyContext::StrategyContext(VehicleStrategy * strategy){
     this->strategy = strategy;
    }

    StrategyContext::~StrategyContext(){

    }

    void StrategyContext :: executeStrategyDecision(vector<Vehicle*> vehicles, Vehicle * currentVehicle){
       strategy->decision( vehicles, currentVehicle);
    }

    void StrategyContext :: executeStrategyOperation(Vehicle * currentVehicle){
      strategy->doOperation(currentVehicle);
    }

