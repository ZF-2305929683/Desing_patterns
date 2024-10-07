#pragma once
#include <iostream>

/*原型模式
通过拷贝构造函数也可以实现对对象中间状态的拷贝，但是需要知道拷贝对象的类型。
暂时无法理解原型模式最大优势在哪。
*/

class Prototype
{
public:
    Prototype() = default;
    virtual ~Prototype(){}
    virtual Prototype* Clone() = 0;
    virtual void show() = 0;
    virtual void operat() = 0;
};


class concrete_Prototype:public Prototype
{
public:
    concrete_Prototype(int count):my_count_(count){}
    concrete_Prototype(concrete_Prototype& other){
        this->my_count_ = other.my_count_;
    }
    ~concrete_Prototype(){}

    Prototype* Clone() override{
        return new concrete_Prototype(*this);
    }

    void show() override{
        std::cout<<my_count_<<"\n";
    }

    void operat() override{
        this->my_count_ -= 5;
    }
private:
    int my_count_;
};