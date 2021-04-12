/*
 * @Author: your name
 * @Date: 2020-04-03 09:37:30
 * @LastEditTime: 2020-04-03 09:42:32
 * @LastEditors: Please set LastEditors
 * @Description: 构造函数不能是虚函数，而析构函数可以是虚析构函数。
 * 例如：当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。如果析构函数不是虚拟的，则只能调用基类析构函数。
 * @FilePath: /C++课程学习记录/虚析构函数.cpp
 */

#include <iostream>
using namespace std;

class Base {
   public:
    Base() { cout << "Constructor: Base" << endl; }
    virtual ~Base() { cout << "Destructor : Base" << endl; }
    // 这里的虚析构函数使得派生类对象释放时， 先寻找基类析构函数， 发现基类析构函数是虚拟的，后去寻找派生类的析构函数
};

class Derived : public Base {
   public:
    Derived() { cout << "Constructor: Derived" << endl; }
    ~Derived() { cout << "Destructor : Derived" << endl; }
};

int main() {
    Base *Var = new Derived();
    delete Var;
    /* Constructor: Base
    Constructor: Derived
    Destructor : Derived
    Destructor : Base */
    return 0;
}
