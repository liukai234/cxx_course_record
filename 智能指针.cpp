/*
 * @Author: your name
 * @Date: 2020-03-13 15:09:46
 * @LastEditTime: 2020-03-19 17:50:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /exception_ptr/3.cpp
 */
#include <iostream>
#include <memory>
using namespace std;

class test{
    public:
    int ret(){
        return a;
    }
    private:
    static int a;
};

int test::a = 5; // 静态成员的定义方法

int main() {
    /* int *p = new int(5);
    delete p;
    p = nullptr; // delete之后要对指针置空
    return 0; */
    // 使用智能指针
    // 智能指针 unique_ptr shared_ptr weak_ptr 用于类的指针, 访问类的成员;
    int a = 5;
    unique_ptr<int> p2{make_unique<int>()};
    // p2 = 5;
    unique_ptr<test> p{make_unique<test>()};
    cout << p->ret() << endl;
}