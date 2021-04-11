#include <iostream>

using namespace std;

class Base {
public:
    Base() = default;
    Base(int a, int b) {}
    // 虚函数必须拥有方法体，带有虚函数的类可以定义对象
    virtual void add(int a, int b) { cout << a + b << endl; }
};

class Dervied : public Base {
public:
    // 只需要初始化直接基类的构造函数
    Dervied(int a, int b):Base(a, b) {}
    // 重载虚函数
    void add(int a, int b) override { cout << string("Dervied: ") << a + b << endl; }
};

class VD : public Base {
public:
    VD():Base(){}
    // 虚函数 =0 则成为纯虚函数，含有纯虚函数的类称为抽象类，抽象类不能定义对象
    virtual void add(int a, int b) = 0;
};

class SubVD : public VD {
public:
    SubVD():VD(){}
    // 纯虚函数必须被实现
    void add(int a, int b) override {
        cout << string("SubVD: ") << a + b << endl;
    }
};

int main() {
    Base base;
    base.add(2, 3);
    Dervied d(2, 3);
    d.add(10, 10);
    SubVD subVd;
    subVd.add(20, 20);
}