#include <iostream>
#include <array>
using namespace std;

// 对于修饰Object来说:
// const并未区分出编译期常量和运行期常量
// constexpr限定在了编译期常量
// constexpr作用：优化!效率!
// constexpr修饰的函数，返回值不一定是编译期常量。It is not a bug, it is a feature.
// const修饰的是类型，constexpr修饰的是用来算出值的那段代码。
/**
 * constexpr修饰的函数，简单的来说，如果其传入的参数可以在编译时期计算出来，那么这个函数就会产生编译时期的值。
 * 但是，传入的参数如果不能在编译时期计算出来，那么constexpr修饰的函数就和普通函数一样了。
 */
constexpr int foo(int i)
{
    return i+10;
}

// 必须定义在方法体外
int a = 2;
// or int a = 2;
// or const int a = 2;
const /* constexpr: constant expression */ int d = 2;
const int *c = &a; // const int *c = &a 底层const
constexpr int *cc = &a; // int * const cc = &a 置为顶层const

int main() {
    // constexpr 把他所定义的对象置为顶层 const
    // 对 top-level const 取地址后结果为 low-level const
    // const int a to const int *a

    constexpr const int *b = &a;
    // constexpr const int *c = b;
    const int* i = cc;
    const int &e = d; // 引用的类型必须与引用的对象类型一致（非常量转换为常量的原则仍适用）
}
