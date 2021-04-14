/*
 * 重载：指有多个相同名字不同参数的函数
 * 隐藏：名字查找先于类型匹配，名字隐藏只在其作用域内隐藏（脱离了它的作用域这个被隐藏的成员又会可见）
 *      派生类的成员将隐藏同名的基类成员，可以通过作用域运算符来使用隐藏的成员
 * 覆盖：利用类型匹配（指参数列表）
 *      覆盖重载的函数：利用using可以把该函数的所有重载实例添加到派生类的作用域中
 */

#include <iostream>
using namespace std;
struct Base {
public:
    virtual int add(int a) { return a * 2; }
    virtual int add(int a, int b) { return a + b; }
};

struct Derived : public Base {
public:
    // 覆盖重载的函数：利用using可以把该函数的所有重载实例添加到派生类的作用域中
    using Base::add;
    int add(int a) { return a; }
    
    // 覆盖（override）只发生在虚函数上，否则称为隐藏（如果不是虚函数，在子作用域内的同名都称为隐藏）
    // 先进行名字查找，所以先判断隐藏
    // int add(int a) override { return a; } // 覆盖虚函数 
    // int add() { return 0; } // 名字隐藏 // 隐藏了基类add的虚函数，他们只在Derived的作用域内隐藏
};

int main() {
    Derived d;
    cout << d.add(1); // cout << 1
}