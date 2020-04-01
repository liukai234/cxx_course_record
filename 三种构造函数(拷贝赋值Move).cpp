/*
 * @Author: your name
 * @Date: 2020-02-24 10:08:45
 * @LastEditTime: 2020-04-01 11:00:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /newclass/1.cpp
 */

#include <iostream>
using namespace std;

class Vector
{
private:
    size_t sz;
    double *elem;

public:
    // 两种构造函数的初始化形式都是没有问题的
    /* Vector(int size){
        sz = size;
        elem = new double(size);
    } */
    // explicit 显示的(用来避免隐式的转化)
    Vector(size_t size)
        : sz{size},
          elem{new double[size]}
    {
    }

    // 赋值构造函数 
    // copy assignment: clean up target and copy // 深拷贝
    // 用于在让两个类相等赋值的时候才会触发 B = A, 并且在B = A发生时, 调用的是B的 operator 元素
    /* Vector &operator=(const Vector& a){ 
        double *p = new double[a.sz];
        for(size_t i = 0; i < a.sz; i++){
            p[i] = a.elem[i];
        }
        delete[] elem; //B中的elem元素
        elem = p;
        sz = a.sz;
        return *this;
    } */

    // Move 赋值函数
    // 
    /* Vector &operator=(Vector&& a){
        elem = a.elem;
        a.elem = nullptr;
        sz = a.sz;
        a.sz = 0;
        return *this;
    } */

    // Move 构造函数
    // move assignment: clean up target and move
    /* Vector(Vector&& a)
        :elem{a.elem},
        sz{a.sz}
    {
        a.elem = nullptr;
        a.sz = 0;
    } */



    // 拷贝构造函数
    // Vector(const Vector &other);

    // 含参数列表的构造函数
    /* Vector(initializer_list<double> lst)
     :sz{lst.size()},
     elem{new double(lst.size())}
    {
        copy(lst.begin(), lst.end(), elem);
    } */

    ~Vector()
    {
        cout << "~exec" << endl;
    }
};

// 发生在用A类初始化B类
/* Vector::Vector (const Vector &other)
    : sz{other.sz},
    elem{new double[other.sz]}
{
    // 相当于此操作
    /* size_t sz = other.sz;
    double* elem = new double[other.sz]; */

    //对新开辟的堆空间 赋予原堆空间的内容
    /*for(size_t i; i < sz; i++){
        elem[i] = other.elem[i];
    }
} */

// Move构造函数


int main(int args, char *argv[])
{
    // 对于参数列表来说: 只能使用以下方式1
    // 对 Vector A = {1.0, 2.0, 3.0};
    // 错 Vector A(1.0, 2.0, 3.0);

    // 对于单个或多个参数来说以下两种方式都是可行的
    /* Vector B(5, 6);
    Vector C = {5, 6}; */

    Vector A(5);
    // Vector B = A; // 用A类初始化B类
    // A.~Vector(); 编译器会自动调用析构函数
    // Vector B = A; // 包含动态内存new, 编译器会选择浅拷贝, 即动态内存的两个栈指针指向同一块堆空间
}
// 再类的外部声明定义函数, 在类的内部定义
// 高内聚, 低耦合
/* Vector::Vector(size_t size)
    : sz{size},
      elem{new double[sz]}
{
} */