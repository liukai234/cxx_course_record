#include <iostream>

template<class T>
class Base {
public:
    explicit Base(int a):a_(a){}
    static T b_;
    // decltype(a_) 中的a_来自于此函数的参数
    auto a(int a_) -> decltype(a_) { return a_; }
private:
    T a_;
};



template<class T>
T Base<T>::b_ = 3;

int main() {
    Base<int> base(0);
    using baseInt = Base<int>;
    std::cout << baseInt::b_;
}
