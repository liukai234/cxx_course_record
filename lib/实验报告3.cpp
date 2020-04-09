/*
 * @Author: your name
 * @Date: 2020-04-07 15:06:39
 * @LastEditTime: 2020-04-09 10:22:09
 * @LastEditors: Please set LastEditors
 * @Description:定义抽象基类Shape，由它派生出3个派生类：
 * Circle(圆形)、Square（正方形）、Rectangle（矩形）。
 * 用虚函数分别计算几种图形面积，并求它们的和。
 * 要求利用基类指针数组，使它的每一个元素指向一个派生类对象。
 * @FilePath: /C++课程学习记录/lib/test.cpp
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename T>
class Shape {
   public:
    virtual const T area() const = 0;
    virtual ~Shape() = default;
};

template <typename T>
class Circle : public Shape<T> {
   public:
    Circle(T r);
    virtual const T area() const;
    virtual ~Circle() = default;
   private:
    T r;
};


template <typename T>
Circle<T>::Circle(T r) : r{r} {};

template <typename T>
T const Circle<T>::area() const { return M_PI * r * r; }

template <typename T>
class Square : public Shape<T> {
   public:
    Square(T length);
    virtual const T area() const;
    virtual ~Square() = default;
   private:
    T length;
};

template <typename T>
Square<T>::Square(T length) : length{length} {};

template <typename T>
T const Square<T>::area() const { return length * length; }

template <typename T>
class Rectangle : public Shape<T> {
   public:
    Rectangle(T length, T width);
    virtual const T area() const;
    virtual ~Rectangle() = default;
   private:
    T length;
    T width;
};

template <typename T>
Rectangle<T>::Rectangle(T length, T width) : length{length}, width{width} {};

template <typename T>
T const Rectangle<T>::area() const { return length * width; }

void test_driver(){ 
    vector<Shape<double>* > vec_shape;
    Circle<double> circle(2.1);
    // cout << circle.area() << endl; // 静态绑定
    vec_shape.push_back(&circle);

    Square<double> square(2.1);
    vec_shape.push_back(&square);

    Rectangle<double> rectangle(2.1, 3.1);
    vec_shape.push_back(&rectangle);

    cout << "面积分别为：";
    for(auto &x : vec_shape) {
        cout << x->area() << " "; // 动态绑定
    }
    cout << endl;
}

int main() { test_driver(); return 0; }