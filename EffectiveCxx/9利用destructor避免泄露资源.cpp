#include <iostream>
using namespace std;

template <class T>
class auto_ptr {
public:
    auto_ptr(T *p = 0) : ptr(p) {}
    ~auto_ptr() { delete ptr; }

private:
    T* ptr;
};

class MyException : public exception {
public:
    string msg() const{ // 此项不是继承的
        return "my exception\n";
    }
};

class ALA {
public:
    virtual void processAdoption() = 0;
private:
    int a_;
};

class Puppy : public ALA {
public:
    virtual void processAdoption() {
        cout << "Puppy::processAdoption\n";
    }
};

class Kitten : public ALA {
    virtual void processAdoption() {

    }
};


int main() {
    /*
     * 局部对象总是会在函数结束时析构，不论函数何时结束
     * 以一个"类似指针的对象p"来取代指针puppy
     * 当p停止使用时析构函数会delete puppy
     */
    Puppy *puppy = new Puppy();
    auto_ptr<ALA> p(puppy);
    puppy->processAdoption();
}