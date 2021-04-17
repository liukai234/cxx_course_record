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
    Base(const Base &&b) noexcept { cout << "Base move copy\n"; }
    Base& operator=(const Base &&b) noexcept { cout << "Base move equal\n"; return *this; }
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