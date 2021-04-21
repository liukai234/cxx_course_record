#include <iostream>

// 默认模板实参
template<class T = std::string>
class Base {
public:
    // TODO: 为了兼容传来的左值和右值，不适用 const T &a; 和 const T && a; 使用 T a和std::move(a);
    explicit Base(T a):a_(std::move(a)){} 
    static T b_;
    T &a();
    // 默认函数实参
    
private:
    T a_;
};

template<typename T> T &Base<T>::a(){ return a_; }

template<class T>
T Base<T>::b_ = 3;

int main() {
    int a = 2;
    Base<int> base3(a); // a 为左值 T& a;
    Base<double> base(1.1); // 1.1 为右值 const T && a;
    std::cout << base.a();
    // 使用默认模板参数
    Base<> baseString(std::string("baseString"));
    std::cout << baseString.a();
}
