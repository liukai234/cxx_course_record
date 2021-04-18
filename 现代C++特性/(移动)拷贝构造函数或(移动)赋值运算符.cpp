#include <iostream>
using namespace std;

/*
 * 这里要明白的一些概念
 * 浅拷贝 shallow copy
 * 深拷贝 deep copy
 * 拷贝构造函数 A(const A& a)
 * 赋值函数 A& operator=(const A& a)
 * 移动拷贝构造函数 A(A && a)            使用时 A b(move(a));
 * 移动赋值函数 A& operator=(A && a)    使用时 A b; b = move(a);
 * // 移动即要清空原对象的内容（这里的移动是之前学习的Move）
 */

/*
 * 一个C++的空类，编译器会加入默认的成员函数
 * 默认构造函数和拷贝构造函数
 * 析构函数
 * 赋值函数（赋值运算符）
 * 取值函数
 * 即使程序没定义任何成员，编译器也会插入以上的函数
 */
class A {
public:
    /*
     * Defaulted Function
     * 默认函数需要用于特殊的成员函数，包括默认构造函数，复制构造函数，析构函数
     */
    A() = default;
    A(const string &s): name_(s){}
    /*
     * 如果是重载双目操作符（即为类的成员函数），就只要设置一个参数作为右侧运算量，而左侧运算量就是对象本身
     * 而 >>或<< 左侧运算量是 cin或cout 而不是对象本身，所以不满足后面一点，就只能申明为友元函数了
     * 如果一定要声明为成员函数，只能成为如下的形式：
     * ostream & operator<<(ostream &output){
     *     output << this->name_;
     *     return output;
     * }
     */
    friend ostream &operator<<(ostream &os, A &a);
    void setName(const string &name) { this->name_ = name; }

    /*
     * A (const A&other)
     * 在C++中，3种对象需要复制，此时拷贝构造函数会被调用
     * 1）一个对象以值传递的方式传入函数体
     * 2）一个对象以值传递的方式从函数返回
     * 3）一个对象需要通过另一个对象进行初始化
     */
    A(const A &a) {
        this->name_ = a.name_ + "1";
    }

    /*
     * 当没有重载赋值函数（赋值运算符）时，通过默认赋值函数来进行赋值操作
     * A a;
     * A b;
     * b=a;
     * 强调：这里a,b对象是已经存在的，是用 a 对象来赋值给b的
     * A& operator = (const A& other)
     *
     * 区分拷贝构造函数和赋值函数
     * 拷贝构造函数是一个对象初始化一块内存区域，这块内存就是新对象的内存区，而赋值函数是对于一个已经被初始化的对象来进行赋值操作
     * 赋值函数是一个等于运算符重载
     */
    A operator=(const A &a) {
        this->name_ = a.name_ + "1";
        return *this;
    }

    A(A &&a) {
        this->name_ = a.name_ + "1";
        a.name_ = "\'Move copy ctor: be cleared\'";
    }

    /*
     * Move 赋值函数和拷贝函数（和普通的拷贝和赋值函数相比，b = a会清空 a 的值）
     * 格式为 A operator=(A &&a)
     * 使用时 b = move(a)
     */
    A operator=(A &&a) {
        this->name_ = a.name_ + "1";
        a.name_ = "\'be cleared\'";
        return *this;
    }


    /*
     * expicitly deleted
     * 禁用成员函数的使用
     */
    void Fun() = delete;

private:
    string name_;
};

ostream &operator<<(ostream &os, A &a) {
    os << a.name_ << " ";
    return os;
}

int main(int argc, char *argv[]){
    A a;

    // A::Fun()=delete 被禁用
    // a.Fun(); // ERROR, Attempt to use a deleted function

    a.setName("123");
    // 拷贝构造函数，使用a来初始化b
    // A b(a); 或 A b = a;

    // 赋值函数，b已经初始化，使用a来给b赋值
    // A b; b = a;
    
    // 移动拷贝构造函数
    // A b(move(a)); 或 A b = move(a); // 将左值a显示的转换为右值std::move(a)
    
    // 移动赋值函数
    // A b; b = move(a);

    // cout << a;
    // cout << b;
}