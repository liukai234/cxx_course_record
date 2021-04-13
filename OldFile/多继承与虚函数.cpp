/*
 * @Author: your name
 * @Date: 2020-02-27 14:40:45
 * @LastEditTime: 2020-04-13 17:36:51
 * @LastEditors: liukai
 * @Description: 多继承与虚函数
 * @FilePath: /C++课程学习记录/多继承与虚函数.cpp
 */
#include <iostream>
using namespace std; 
 
class Base{
public:
    Base(){
        cout << "Base Base()\n";
    }
    virtual void foo(){
        cout << "Base foo()\n";
    }
    virtual ~Base(){
        cout << "dis Base foo()\n";
    }
};

class Derived : public Base {
public:
    Derived(){
        cout << "Derived() Derived()\n";
    }
    virtual void foo(){
        cout << "Derived foo()\n";
    }

    virtual ~Derived(){
        cout << "dis Derived foo()\n";
        
    }
};

int main() {
    // Derived d1;
    Base *b1 = new Derived;
    b1->foo();
    delete b1;
    // 入栈方式: Base先入栈, 然后Derived入栈, 然后delete时先析构Derived, 然后析构Base
    return 0;
}