#pragma once
#include <string>
#include <iostream>
/*工厂设计模式*/

/*一.简单工厂模式
优点：易于理解
缺点：当需要修改拓展方法时，需要修改simplefactory类，违反开闭原则。
*/

class car
{
public:
    car(std::string name) :name_(name){}
    virtual void show() = 0;

protected:
    std::string name_;
};

class BWM : public car
{
public:
    BWM(std::string name):car(name){}
    void show() override{
        std::cout<<"获取一辆"<<name_<<"汽车"<<"\n";
    };

};

class AUID : public car
{
public:
    AUID(std::string name):car(name){}
    void show() override{
        std::cout<<"获取一辆"<<name_<<"汽车"<<"\n";
    };
};


enum class Car_type{BWM_,AUID_};

class simplefactory
{
public:
    car* creator(Car_type car_){
        switch (car_)
        {
        case Car_type::BWM_:
            return new BWM("BWM");
        case Car_type::AUID_:
            return new AUID("AUID_");
        default:
            break;
        }
    }
};


/*工厂方法
优点:拓展新产品方法时，只需要新添加一个产品类与一个工厂类。
缺点：当新增同一属性的物品时采用新添加一个产品类与一个工厂类的方法不利于维护。
*/

class Factory
{
public:
    virtual car* creator(std::string name) = 0;
};

class BWMFactory : public Factory
{
public:
    car* creator(std::string name) override{
        return new BWM(name);
    };
};

class AUIDFactory : public Factory
{
public:
    car* creator(std::string name) override{
        return new BWM(name);
    };
};


/*抽象工厂方法
优点：相比较于工厂方法扩展时不需要添加过多的类。
缺点：每当增加新的产品类型时需要修改抽象工厂的基类与子类，不遵守开闭原则。
*/

class light
{
public:
    virtual void show() = 0;
};

class BMWlight : public light
{
public:
    void show() override{
        std::cout<<"获取一盏BMW车灯"<<"\n";
    };
};

class AUIDlight : public light
{
public:
    void show() override{
        std::cout<<"获取一盏AUID车灯"<<"\n";
    };
};


class AbstractFactory
{
public:
    virtual car* creator(std::string name) = 0;
    virtual light* creator_light() = 0;
};

class BWMAbstractFactory : public AbstractFactory
{
public:
    car* creator(std::string name) override{
        return new BWM(name);
    };
    light* creator_light() override{
        return new BMWlight();
    };   
};


class AUIDAbstractFactory : public AbstractFactory
{
public:
    car* creator(std::string name) override{
        return new BWM(name);
    };
    light* creator_light() override{
        return new AUIDlight();
    };   
};