#include <iostream>
#include <memory>

using namespace std;

/*
 * 在构造函数内阻止资源泄露
 * C++原则：面对尚未构造好的对象，C++拒绝其调用destructor（否则会降低构造的速度）
 * 类内的指针常量必须通过ctor成员初值链表加以初始化，因为不会再有其他方式初始化其
 * 将derived视为资源，交给局部对象shared_ptr来管理，如此不必手动释放资源
 */

/*
template <class T>
class auto_ptr {
public:
    auto_ptr(T *p = 0) : ptr(p) {}
    ~auto_ptr() { delete ptr; }

private:
    T* ptr; // 一个非new方式的对象
};
*/

class Derived {
public:
    Derived(const string& fileName):fileName_(fileName){}
    string gether() { return fileName_; }
    ~Derived(){ cout << "derived be dtor\n"; }
private:
    const string fileName_;
};

class Base {
public:
    /*
     * [注] 当fileName为空时不构造derived
     */
    Base(const string& name, const string& fileName):name_(name), derived(fileName != "" ? new Derived(fileName) : 0){}
    shared_ptr<Derived> getDerived() { return derived; }
    ~Base(){ cout << "base be dtor\n"; }
private:
    const string name_;
    const shared_ptr<Derived> derived;
};

void driver() {
    Base base("name", "fileName");
    cout << base.getDerived()->gether() << endl;

    /*
     * [注] 当fileName为空时不构造derived
     */
    Base base1("name", "");
    cout << (base1.getDerived() != nullptr ? base1.getDerived()->gether() : "base1.derived is nullptr") << endl;
    /* ? */ cout << (2 == 2 ? "y" : "n") << endl;
}
int main() {
    driver();
}