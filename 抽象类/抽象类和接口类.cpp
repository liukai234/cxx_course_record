/*
 * 抽象类与接口类
 * (1) 含有纯虚函数的类叫做抽象类，抽象类可以包含非虚函数，抽象类的子类也可以是抽象类，只有子类把抽象类中的所有纯虚函数都实现了以后，子类才可以实例化对象;
 * (2) 只含有纯虚函数的抽象类叫做接口类，接口类没有.cpp文件，只有.h头文件，也没有成员变量和普通成员函数，构造函数和析构函数;
 * (3) 抽象类和接口类都无法直接实例化对象;
 */

#include <iostream>
#include <string>

using namespace std;

// 接口类
class PureVirtualBase {
public:
    virtual void add(int a, int b) = 0;
    virtual void sub(int a, int b) = 0;
};

// 接口类
class PureVirtualBase2 {
public:
    virtual void mul(int a, int b) = 0;
};

// 抽象类
class PureVirtualDervied : public PureVirtualBase{
public:
    virtual void add(int a, int b) { cout << "PureVirtualDervied: " << a + b << endl;}
    // sub 纯虚函数没有实现
};

class SS : public PureVirtualDervied, public PureVirtualBase2{
public:
    virtual void sub(int a, int b) { cout << "SS: " << a - b << endl; }
    virtual void mul(int a, int b) { cout << "SS: " << a * b << endl; }
};

int main() {
    SS p;
    p.mul(5, 2);
}