/*
 * @Author: your name
 * @Date: 2020-03-19 17:26:27
 * @LastEditTime: 2020-04-01 10:57:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/对象指针.cpp
 */
#include <iostream>
using namespace std;

class Time; // 对类的提前声明引用
// 友元函数和友元类
class Time{
   public:
    Time(int, int, int);
    int hour;
    int minute;
    int sec;
    void get_time() const; // 常成员函数
    
};

Time::Time(int h, int m, int s) {
    hour = h;
    minute = m;
    sec = s;
}

void Time::get_time() const{
    cout << hour << " : " << minute << " : " << sec << endl;
}

int main() {
/*
    a是一个对象指针, 并没有为其开辟空间
    A *a;
    a->Hello();
*/
    // 指向对象的常指针
    Time t1(10, 13, 56); // 常对象, 普通成员函数不能修改对象中数据成员的值
    int *p1 = &t1.hour;
    cout << *p1 << endl;
    t1.get_time();
    Time *p2 = &t1;
    p2->get_time();
    void(Time::*p3)(); // 定义指向Time类的公用成员函数的指针变量
    p3 = &Time::get_time; // 使p3指向Time类共用成员函数get_time
    // void(Time::*p3)() = &Time::get_time; 定义时同时指定其指向
    (t1.*p3)();
    return 0;
}