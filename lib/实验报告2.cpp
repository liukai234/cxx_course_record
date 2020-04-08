/*
 * @Author: your name
 * @Date: 2020-04-07 17:45:13
 * @LastEditTime: 2020-04-07 17:45:33
 * @LastEditors: Please set LastEditors
 * @Description: 自加自减运算符的前后置重载
 * @FilePath: /C++课程学习记录/lib/实验报告2.cpp
 */


#include <iostream>
using namespace std;

class Point {
   public:
    Point();
    Point(int x, int y);
    Point operator++();     // 前置
    Point operator++(int);  // 后置
    Point operator--();     // 前置
    Point operator--(int);  // 后置
    void set(int x, int y);
    friend ostream &operator<<(ostream &output, Point &p);

   private:
    int x;
    int y;
};
Point::Point() {}
Point::Point(int x, int y) : x{x}, y{y} {}
Point Point::operator++() {
    ++x;
    ++y;
    return *this;
}
Point Point::operator++(int) {
    Point temp(*this);
    ++x;
    ++y;
    return temp;
}
Point Point::operator--() {
    --x;
    --y;
    return *this;
}
Point Point::operator--(int) {
    Point temp(*this);
    --x;
    --y;
    return temp;
}
ostream &operator<<(ostream &output, Point &p) {
    output << "(" << p.x << "," << p.y << ")";
    return output;
}
void Point::set(int x, int y) {
    this->x = x;
    this->y = y;
}

void test_driver() {
    Point p(5, 6);
    Point p2;
    cout << "p = " << p << endl;
    p2 = p++;
    cout << "p++ = " << p2 << endl;
    p.set(5, 6);
    p2 = ++p;
    cout << "++p = " << p2 << endl;
    p.set(5, 6);
    p2 = p--;
    cout << "p-- = " << p2 << endl;
    p.set(5, 6);
    p2 = --p;
    cout << "--p = " << p2 << endl;
}
int main() { test_driver(); }