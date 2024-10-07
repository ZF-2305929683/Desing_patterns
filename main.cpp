#include <iostream>
#include "Prototype.h"
#include <memory>

int main(){
    std::unique_ptr<Prototype> protype(new concrete_Prototype(20));
    protype->show();
    protype->operat();

    std::unique_ptr<Prototype> protype2(protype->Clone());

    protype->show();
    protype2->show();

}