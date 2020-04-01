/*
 * @Author: your name
 * @Date: 2020-03-19 17:58:39
 * @LastEditTime: 2020-04-01 10:56:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /test/test.cpp
 */

#include <iostream>

using namespace std;

class Test {
   public:
   // 一旦有了其他的构造函数则默认的构造函数就失效了!!!
    // Test(){}
    Test(int a) {}
    Test(int a, int b) {}
};

int main() {
    Test *test1 = new Test(1); 
    delete test1;
    Test t1(1), t2(2);
    
    // 无参的
    // test1 = new Test[2]; // wrong 有其他构造函数, 默认构造函数失效, 必须手动重写默认构造函数

    delete[] test1;
    Test test2[2] = {Test(1,2), Test(2, 3) }; // 2个参数的
    test1 = test2;
    Test* test[3] = {new Test(1), new Test(2), new Test(3) }; // 2个参数的
    delete test[0];
    delete test[1];
    delete test[2];
    return 0;
}