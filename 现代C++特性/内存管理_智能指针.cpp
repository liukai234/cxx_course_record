/*
 * shared_ptr 允许多个指针指向同一个对象 引用计数
 * unique_ptr "独占"所指向的对象
 * weak_ptr 弱引用，不影响 shared_ptr 的引用数量
 */

#include <iostream>
#include <memory>


using namespace std;

int main() {
    shared_ptr<string> p1 = make_shared<string>(string("123"));
    cout << p1.use_count(); // 1 引用计数
    shared_ptr<string> p2;

    p2 = p1;
    // p1.use_count() = 2, p2.use_count() = 2; p1 和 p2 指向同一个对象
    cout << p1.use_count() << p2.use_count();

    string *s = new string("s");
    delete s;
    // 解决空悬指针 但是这也只是提供了有限的保护 若有多个指针指向相同的内存
    // 重置指针为空只对该指针有效，对其他指针是没有作用的
    s = nullptr;
    
    shared_ptr<int> p3(new int(3)); // OK, 智能指针指向new返回值，必须使用直接初始化形式

    // unique_ptr 没有类似 make_shared 的函数，只能使用new来直接初始化
    unique_ptr<string> u1(new string("234"));
    // 且不可拷贝和赋值，使用reset和release来转移
    unique_ptr<string> u2;
    // u2 = u1; // ERROR
    u2.reset(u1.release());
    
    // weak_ptr 不会改变shared_ptr引用计数
    // w.expired 如果 use_count = 0返回true，否则返回false
    // w.lock    如果 expired 返回true则返回空shared_ptr，否则返回指向w对象的shared_ptr
    weak_ptr<string> w(p1);
    w.expired();
    w.lock();
    
    // 判断引用计数是否为0，对象是否被释放掉，为释放掉才进入if
    if(shared_ptr<string> np = w.lock()) {
        // 在if中np与p1共享对象
    }
}