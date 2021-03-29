#include <iostream>
#include <memory>

using namespace std;

/*
template <class T>
class auto_ptr {
public:
    auto_ptr(T *p = 0) : ptr(p) {}
    ~auto_ptr() { delete ptr; }

private:
    T* ptr;
};
*/

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
    shared_ptr<ALA> p(puppy);     // or shared_ptr<ALA> p(new Puppy());
    p->processAdoption();

    /*
     * auto_ptr(C++98)存在一些问题，采用copy语义来转移指针资源，转移的同时将原指针置为NULL，
     * 这与通常理解的copy行为不一致，除此之外当多个auto指针指向同一个资源释放时也会产生问题
     * unique_ptr、shared_ptr、weak_ptr(C++11)
     * shared使用引用计数，不会产生资源释放时的问题
     * unique用于多线程
     */

    string *s = new string("");
    shared_ptr<string> as(s);
    s->push_back('4');
    cout << endl << as->length();
    shared_ptr<string> as2 = as;      // 如果使用auto指针则as被置空，资源转移到as2
    as2->push_back('0');           // 多个shared指针共享一个对象
    cout << endl << as->length();
    cout << endl << as2->length();
}