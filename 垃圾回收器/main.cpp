/*
 * g++ main.cpp -o main.exe -D DEBUG -std=c++14
 * for(auto &x : inputStaff) { std::cout << *x; }
 */

#include <iostream>
#include <list>
#include "ManageAllocation.h"
#include "Object.h"

#ifdef DEBUG
#include "dbg.h"
#endif


class Add : public Object {
public:
    explicit Add(int a) : a_ {a} {}
    explicit Add() {}
    int a() const { return a_; }

private:
    int a_;
};

class B : public Add {

};

int main() {

    Add *add1 = new Add(5);
    Add *add2 = new Add(2);
    B *b = new B();
    B *b2 = new B();

    *b2 = *b;
    *add2 = *add1;
    ManageAllocation::getAllObjPointer();

    b2->refCount();
    add2->refCount();

#ifdef DEBUG
    dbg(add1->refCount());
    dbg(add2->refCount());
#endif
//    if(add1->refCount() == 1) delete add1; // 引用为0时释放资源
//    if(add2->refCount() == 0) delete add2; // 程序结束前释放所有资源
    return 0;
}
