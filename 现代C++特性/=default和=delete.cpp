#include <iostream>
using namespace std;

class A {
public:
    /*
     * Defaulted Function
     * 默认函数需要用于特殊的成员函数，包括默认构造函数，复制构造函数，析构函数
     */
    A() = default;

    /*
     * expicitly deleted
     * 禁用成员函数的使用
     */
    void Fun() = delete;
};

int main(int argc, char *argv[]){
    A a;
    // a.Fun(); // ERROR, Attempt to use a deleted function
}