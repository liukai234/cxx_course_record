//
// Created by lk234 on 2021/3/26.
//
#include <iostream>
#include <sstream>

using namespace std;

class Base {
public:
    Base() { cout << "Base ctor\n"; }
    Base(const Base &b) { cout << "Base copy\n"; }
    Base& operator=(const Base &b) { cout << "Base equal\n"; return *this; }
    Base(Base &&b) noexcept { cout << "Base move copy\n"; }
    // 移动赋值后等号右侧对象应进入可析构状态，指针都应置为nullptr，所以这里不可以是const的
    Base& operator=(Base &&b) noexcept { cout << "Base move equal\n"; return *this; }
};

class Derived : Base {
public:
    Derived() : Base(){};
};

int main() {
    Derived d;
    Derived d2;
    d2 = std::move(d);
}