#include <iostream>

using namespace std;

class Base {
public:
    Base() = default;
    Base(int a, int b) {}
    // 虚函数必须拥有方法体，带有虚函数的类可以定义对象
    // 定义他为虚函数是为了允许用基类的指针来调用子类的这个函数，实现多态
    // 多态性: 对同一消息, 不同的对象有不同的响应方式
    // 但子类不必须重载虚函数
    virtual void add(int a, int b) { cout << "Base: " << a + b << endl; }
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
    // 定义纯虚函数是为了实现一个接口，起到一个规范的作用，规范继承这个类的程序员必须实现这个函数
    // 同样会实现多态性，不过和虚函数的主要区别在下一条
    // 在基类中的这个虚函数含有方法体时其是无意义的
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