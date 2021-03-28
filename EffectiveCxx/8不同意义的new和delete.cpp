#include <iostream>
using namespace std;

class A {
public:
    A(int a, int b);
    void print() { cout << a_ << " " << b_ << endl; }
    void init(int a, int b) { a_ = a; b_ = b; }
    ~A() = default;
private:
    int a_, b_;
};

A::A(int a, int b):a_(a), b_(b) {}

int main() {
    /* stack */                A a(5, 6);
    /* heap new operator */    A *a1 = new A(5, 6);
    /* operator new */         void *a2 = operator new(sizeof(A)); static_cast<A*>(a2)->print();
    /* placement new */        A* a3= new (a2) A(2, 3); a3->print();

    /*
     * 单例懒汉分配内存
     * 多线程时 2 和 3 的顺序不明确，此时用operator new + placement new来确定顺序
     */
    /* 对象指针 */                A *p = nullptr;
    /* 1. 分配内存 */             A *a4 = static_cast<A*> (operator new(sizeof(A)));
    /* 2. 构造对象 */             new (a4) A(2, 3);
    /* 3. p指向内存 */            p = a4;
    p->print();
    /*
     * new p 等价于 void *a2 = operator new(sizeof(A)); A* a3= new (a2) A(2, 3);
     * 先使用operator new分配后用placement new构造
     *
     * delete p 等价于 p->~A(); operator delete(p);
     * 先析构后使用operator delete释放
     */
    delete p;

    // Array
    string *ps = new string[10];
    delete [] ps;
}