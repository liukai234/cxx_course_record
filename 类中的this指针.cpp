/*
 * @Author: your name
 * @Date: 2020-02-25 21:26:04
 * @LastEditTime: 2020-04-01 10:59:53
 * @LastEditors: Please set LastEditors
 * @Description: 类中的 this 指针
 * @FilePath: /newclass/3.cpp
 */

#include <iostream>
using namespace std;

// 普通的成员函数一般都隐含了一个this指针, this指针指向类的对象本身, 因为普通成员函数
// 总是具体的属于类的某个具体对象的, 当函数被调用时, 系统会把当前对象的起始地址赋给this
// 指针. 通常情况下, this时缺省的, 如函数fn()实际上是this->fn()

// 与普通函数相比, 静态成员属于类本身, 而不作用于对象, 因此她不具有this指针, 正因为它没有指向某一个对象
// 所以他没有指向某一个对象, 所以他无法访问属于类对象的非静态成员比那辆和非静态成员函数, 他只能调用其余的
// 静态成员函数和静态成员变量.

// 从另一个角度分析, 由于静态成员函数和静态成员变量在类实例化之前就已经存在可以访问, 而此时非静态成员还是不存在的
// 因此,静态成员不能访问非静态成员


//类的非静态成员函数, 真实的参数比所写的参数多1 (多一个this指针)
// 并不是每个对象的空间中都存放着一个this指针(因为可能对象中全部是静态成员)
class Box{
private:
    double length;
public:
    static int a; // 静态成员被存放在静态区, 一个类的多个对象共用一块静态区
    Box(double input_length){
        length = input_length;
    }
    Box *get_address(){
        // this 是一个指针, 指针类型位Box *
        return this;
    }
};

int main(){
    Box::a = 5;
    Box box(5);
    Box *ptr = box.get_address();
    cout << ptr << endl;
}