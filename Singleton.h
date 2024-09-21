#pragma once
#include <utility>

/*单例设计模式实现*/

/*一.模板实现单例设计模式
好处：通用，不需要为每个类写一个单例函数。使用简洁。
问题：由于实现与定义都在头文件中，因此可能存在多个源文件包含头文件后创建多个静态单例对象。
*/

template<typename T,typename... Args>
class Singleton
{
private:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    template<typename... Ts>
    static T& Get_instance(Ts&&... pragma){
        static T instance(std::forward<Ts>(pragma)...);
        return instance;
    }
};


/*二.饿汉单例设计模式
好处：在访问对象方法之前就存在了单例对象，不存在线程安全问题。
问题：可能会浪费资源。静态对象的定义应该放在CPP文件中，不然会出现静态对象重定义问题。
*/
class Singleton_hungry
{
private:
    static Singleton_hungry instance;

    Singleton_hungry() = default;
    Singleton_hungry(const Singleton_hungry&) = delete;
    Singleton_hungry& operator=(const Singleton_hungry&) = delete;
public:
    static Singleton_hungry& Get_instance(){
        return instance;
    }
};



/*二.懒汉单例设计模式
好处：节省资源。
*/
class Singleton_lazy
{
private:
    Singleton_lazy() = default;
    Singleton_lazy(const Singleton_lazy&) = delete;
    Singleton_lazy& operator=(const Singleton_lazy&) = delete;
public:
    static Singleton_lazy& Get_instance(){
        static Singleton_lazy instance;
        return instance;
    }
};

static int a = 20;