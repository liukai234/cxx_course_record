/*
 * @Author: liukai
 * @Date: 2020-02-22 13:37:31
 * @LastEditTime: 2020-03-19 18:02:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen2/mytest.cpp
 */

#include <iostream>
using namespace std;

class Add {
   public:
    // explicit 显性的
    explicit Add(const int& a) : num(a) {}
    int Num() { return num; }
    ~Add() {}

   private:
    int num;
};

int main(int args, char* argv[]) {
    // 意义:
    // 如果没有explicit的话就相当于 Add temp(5); Add obj = temp; 先创建临时对象, 然后进行赋值
    // 如果有explicit就不允许发生这种先创建后赋值的现象, 
    // Add add = 5; // wrong
    Add add(5); 

    cout << add.Num() << endl;

    return 0;
}