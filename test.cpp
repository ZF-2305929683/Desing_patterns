#include "test.h"
#include "Singleton.h"
#include <iostream>


void func(){
    Singleton_hungry & lazy = Singleton_hungry::Get_instance();
    std::cout<<&lazy<<"\n";
    std::cout<<&a<<"\n";
}