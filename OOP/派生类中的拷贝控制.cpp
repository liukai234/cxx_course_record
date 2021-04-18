#include <iostream>

using namespace std;

class Base {
public:
    Base(int i, string &s):i(i), s(s){}
    Base(const Base &b) { this->i = b.i; this->s = b.s; cout << "Base copy ctor\n"; }
    Base &operator=(const Base &b) { this->i = b.i; this->s = b.s; cout << "Base copy operator=\n"; return *this; }
    Base(Base &&b) noexcept { this->i = b.i; this->s = b.s; b.i = 0; b.s = ""; cout << "Base move ctor\n"; }
    Base &operator=(Base &&b) noexcept { this->i = b.i; this->s = b.s; b.i = 0; b.s = ""; cout << "Base move operator=\n"; return *this; }
    ~Base(){ cout << "dtor\n"; }
    int i;
    string s;
};

/*
 * 如果派生类中的拷贝控制操作是被删除的则派生类中对应的操作也是被删除的，原因是派生类在执行拷贝控制操作时无法操作基类的部分
 * 在派生类内部，把派生类作为基类，被删除或定义的拷贝控制操作会影响内部其他拷贝控制操作
 */
class Derived: public Base {
public:
    Derived(int i, string &s):Base(i, s){}
};

int main() {
    string s("string");
    Derived b(1, s);
    Derived b2 = std::move(b); // 移动构造 // 之后不应再次使用b，调用std::move() 就意味着除了销毁或赋值它，不再使用它
    b = b2; // 拷贝构造 // 对 b 赋值
    cout << "d.s: " << b2.s << " b.s: " << b.s << endl;
}