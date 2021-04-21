/*
 * 模板 template
 * OOP和泛型编程都能处理在编写程序时不知道类型的情况
 * 不同之处在于：OOP能处理类型在程序运行之前都未知的情况；而在泛型编程中，在编译时就能获知类型了
 */

#include <iostream>
#include <cstring>
using namespace std;

// 模板函数
template <typename T>
int compare(const T &v1, const T &v2) {
    if(v1 < v2) return -1;
    if(v1 > v2) return 1;
    return 0;
}

// 模板类型参数
template <typename T>
T foo(T p) {
    T q = p;
    return q;
}

// 模板非类型参数
template<unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

// 编写类型无关的代码
// 模板程序应尽量减少对实参类型的要求
template<typename T>
int compare3(const T& v1, const T& v2) {
    if(less<T>() (v1, v2)) return -1;
    if(less<T>() (v2, v1)) return 1;
    return 0;
}


// 类模板
template<typename T>
class Blob {
public:
    explicit Blob<T>(T i):i(i){}
    T ret();

private:
    T i;
};

template<typename T>
T Blob<T>::ret() {
    return i;
}
// 模板类型别名
template<typename T> using TP = pair<int, T>;

// template<typename T>
// using baseInt = Base<T>;

// baseInt<double> base1(1.0);


// 以上这种类型别名有别与以下这种
// using baseInt = Base<int>;
// std::cout << baseInt::b_;

// 同时使用这俩种 baseInt 的话会产生冲突

int main() {
    // 编译器用推断出的模板参数来实例化一个特定版本的函数
    cout << compare(0, 1) << endl;
    cout << foo(string("string")) << endl;
    Blob<int> b(1);
    cout << b.ret() << endl;

    // 模板类型别名
    TP<string> s;
    s = make_pair(1, string("string"));
    cout << s.first << " " << s.second << endl;
}