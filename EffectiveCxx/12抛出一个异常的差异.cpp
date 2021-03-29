#include <iostream>

using namespace std;

/*
 * 虚函数是最佳匹配，catch是最先匹配
 */

class Base {
public:
    Base(int a):a_(a){}
    string get(){ return "Base.get()\n"; }
private:
    int a_;
};

class Derive : public Base {
public:
    Derive(int a, int b = 0):Base(a), b_(b){}
    string get() { return "Derive.get()\n"; }
private:
    int b_;
};

/*
 * throw是一种基于继承的，可以利用throw持续传播，throw抛出的总是一个副本，catch时若不加引用会再次产生一个副本
 * [!!] 一个对象作为exception被抛出是总是发生复制
 * （若catch字句得到的不是副本，控制权一旦离开try块，derive就脱离了生存空间scope，就会被析构
 * 那么catch会得到一个已经析构的版本，这是没有意义的）
 */

void rethrow() {
    try{ Derive derive(2); throw derive; }
    catch(Derive& derive) { cout << derive.get(); throw; }
}

int main() {
    try{ rethrow(); }
    catch (Base &base) { cout << base.get(); }
}