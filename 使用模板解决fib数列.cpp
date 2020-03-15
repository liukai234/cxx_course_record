/*
 * @Author: your name
 * @Date: 2020-03-03 16:51:24
 * @LastEditTime: 2020-03-03 19:58:23
 * @LastEditors: Please set LastEditors
 * @Description: fibÄ£°åµÝ¹é
 * @FilePath: /wanmen3/fib.cpp
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

template <unsigned int count>
struct Fib {
    static constexpr const unsigned int value =
        Fib<count - 1>::value + Fib<count - 2>::value;
};
template <>
struct Fib<0> {
    static constexpr const unsigned int value = 0;
};
template <>
struct Fib<1> {
    static constexpr const unsigned int value = 1;
};

int main() {
    cout << "Fib<800>:: " << Fib<800>::value << endl;
    return 0;
}