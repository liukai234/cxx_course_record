/*
 * 流操作
 */
#include <iostream>

using namespace std;

class A {
public:

    A() = default;
    A(const string &s): name_(s){}
    /*
     * 如果是重载双目操作符（即为类的成员函数），就只要设置一个参数作为右侧运算量，而左侧运算量就是对象本身
     * 而 >>或<< 左侧运算量是 cin或cout 而不是对象本身，所以不满足后面一点，就只能申明为友元函数了
     * 如果一定要声明为成员函数，只能成为如下的形式：
     * ostream & operator<<(ostream &output){
     *     output << this->name_;
     *     return output;
     * }
     */
    friend ostream &operator<<(ostream &os, A &a);
    void setName(const string &name) { this->name_ = name; }


    A(const A &a) {
        this->name_ = a.name_ + "1";
    }

    /*
     * expicitly deleted
     * 禁用成员函数的使用
     */
    void Fun() = delete;

private:
    string name_;
};

ostream &operator<<(ostream &os, A &a) {
    os << a.name_ << " ";
    return os;
}

int main(int argc, char *argv[]){
    A a;

    // A::Fun()=delete 被禁用
    // a.Fun(); // ERROR, Attempt to use a deleted function

    a.setName("123");
}