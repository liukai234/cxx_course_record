/*
 * @Author: your name
 * @Date: 2020-02-25 21:26:04
 * @LastEditTime: 2020-02-25 21:44:43
 * @LastEditors: Please set LastEditors
 * @Description: 类中的 this 指针
 * @FilePath: /newclass/3.cpp
 */

#include <iostream>
using namespace std;

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