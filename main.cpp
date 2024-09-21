#include <iostream>
#include "test.h"
#include "Singleton.h"

int main(){
    Singleton_hungry &lazy = Singleton_hungry::Get_instance();
    std::cout<<&lazy<<"\n";
    std::cout<<&a<<"\n";
    func();
}