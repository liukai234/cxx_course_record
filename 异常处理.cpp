/*
 * @Author: your name
 * @Date: 2020-03-11 18:07:17
 * @LastEditTime: 2020-03-11 18:30:07
 * @LastEditors: Please set LastEditors
 * @Description: Exception
 * @FilePath: /exception/1.cpp
 */
// 在运行期间转移程序控制权的方式

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class MyException : public exception {
    public:
    string msg() const{ // 此项不是继承的
        return "my exception\n";
    }
};

class A {
    public:
    A(){cout << "A construct\n "; }
    ~A(){cout << "A distruct\n"; }
};

int main() {
    try{
        A a;
        // 在抛出异常时会自动调用析构函数;
        throw MyException();
    } catch (MyException &e) {
        std::cout << "MyException\n";
        std::cout << e.msg();
    }
    return 0;
}