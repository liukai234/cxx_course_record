/*
 * @Author: your name
 * @Date: 2020-02-26 21:41:06
 * @LastEditTime: 2020-02-26 21:45:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /newclass/5.cpp
 */
#include <iostream>
using namespace std;

class Base{
public:
    void foo(){
        cout << "Base foo()\n";
    }
};

// 定义类的继承方式, 公有化继承, 私有化继承
class Derived : private Base{
public:
    void bar(){
        foo();
    }
};

int main(){
    Derived d1;
    d1.bar();
}