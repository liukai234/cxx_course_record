/*
 * @Author: your name
 * @Date: 2020-04-10 18:02:41
 * @LastEditTime: 2020-04-10 18:58:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/thread多线程/point.cpp
 */

#include <iostream>
#include <thread>

using namespace std;

// 3.functor (Funciton Object)
class Base {
   public:
   // 重载operator ()
    void operator()(int x) {
        while (x-- > 0) {
            cout << x << endl;
        }
    }
    // 非静态成员
    void fun1(int x) {
        while (x-- > 0) {
            cout << x << endl;
        }
    }
    // 静态成员
    static void fun2(int x) {
        while (x-- > 0) {
            cout << x << endl;
        }
    }
};

int main() {
    thread t(Base(), 10);
    // Base b;
    // thread t(&Base::fun1, &b, 10);
    // thread t(&Base::fun2, 10);
    t.join();
    return 0;
}