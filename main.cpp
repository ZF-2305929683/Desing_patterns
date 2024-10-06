#include <iostream>
#include "Factory.h"
#include <memory>

int main(){
    std::unique_ptr<AbstractFactory> BWM_FACTORY(new BWMAbstractFactory());
    std::unique_ptr<AbstractFactory> AUID_FACTORY(new AUIDAbstractFactory());
    std::unique_ptr<car> bwm_car(BWM_FACTORY->creator("bwm"));
    std::unique_ptr<car> auid_car(AUID_FACTORY->creator("auid"));

    std::unique_ptr<light> bwm_light(BWM_FACTORY->creator_light());
    std::unique_ptr<light> auid_light(AUID_FACTORY->creator_light());

    bwm_car->show();
    bwm_light->show();

    auid_car->show();
    auid_light->show();
}