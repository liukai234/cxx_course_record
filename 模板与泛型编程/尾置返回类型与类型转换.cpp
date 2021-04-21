#include <iostream>

// 标准库中的类型转换模板
#include <type_traits>

template<class T>
class Base {
public:
    explicit Base(int a):a_(a){}
    static T b_;
    // decltype(ret) 中的ret来自于此函数ret的参数
    // 脱引用操作 [type_traits] std::remove_reference<decltype(ret)>::type 
    // 如果 ret 返回 *beg 的话，返回的结果是解引用的，解引用运算符将返回左值，因此是一个类型的引用
    // 如：string 返回 string&，int 返回 int&
    auto ret(int ret) -> /*decltype(ret)*/ typename std::remove_reference<decltype(ret)>::type { return ret; }
private:
    T a_;
};

template<class T>
T Base<T>::b_ = 3;

int main() {
    Base<int> base(0);
    using baseInt = Base<int>;
    std::cout << baseInt::b_ << "\n";
    int a = base.ret(5);
    std::cout << a << "\n";
}
