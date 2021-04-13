/*
 * 访问控制与继承
 * 1. 派生列表中的派生访问说明符：公有继承，保护继承，私有继承
 * 派生访问说明符对于派生类的成员能否访问其直接基类的成员没什么影响，对基类成员的访问权限只与基类中的访问说明符有关
 * 派生类可以访问基类的公有成员和保护成员，不能访问私有成员
 * 派生访问说明符的目的是控制派生类用户（包括派生类的派生类在内）对于基类成员的访问权限，这里派生类的用户是指使用派生类定义的对象
 * 2. 基类中的访问说明符：公有，保护，私有
 * 派生类可以访问基类的公有成员和受保护成员
 */

/*
 * 默认的继承保护级别
 * 使用class关键字定义的派生类是私有继承的，默认成员属性为private
 * 使用struct关键字定义的派生类是公有继承的，默认成员属性为public
 * [!!] 除此之外class和struct无其他区别
 */
#include <iostream>
using namespace std;
class Base {
public:
    void pub_mem() { cout << "pub_mem\n"; }
protected:
    void prot_mem() { cout << "prot_mem\n"; }
private:
    void priv_mem() { cout << "priv_mem\n"; }
};

class PublicDerived : public Base {
public:
    void deri() {
        pub_mem();
        prot_mem();
        // 派生类可以访问基类的公有成员和受保护成员
        // priv_mem();
    }
};

class ProtectedDerived : protected Base {
public:
    void deri() {
        pub_mem();
        prot_mem();
        // priv_mem();
    }
};

// class 默认继承方式为 private
class PrivateDerived : private Base {
public:
    void deri() {
        pub_mem();
        prot_mem();
        // priv_mem();
    }
};

int main() {
    Base b;
    b.pub_mem(); // 对象可以使用的只有类中的公有成员
    PublicDerived publicDerived;
    publicDerived.deri();
    publicDerived.pub_mem();
    ProtectedDerived protectedDerived;
    protectedDerived.deri();
    PrivateDerived privateDerived;
    protectedDerived.deri();
}