/*
 * @Author: your name
 * @Date: 2020-03-02 16:46:49
 * @LastEditTime: 2020-04-01 10:55:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen3/test.cpp
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 模板类
template <typename T>
class Vector {
   public:
    Vector(int size_param) { cout << "<int>\n"; }
};

// 全特类
template <>
class Vector<float> {
   public:
    Vector(float size_param) { cout << "<float>\n"; }
};

// 模板函数
template <typename T>  // 每一个函数或类前都需要template
const T &Max(const T &a, const T &b) {
    return a > b ? a : b;
}

// 函数全特化
template <>
const int &Max(const int &a, const int &b) {
    cout << "int \n";
    return a > b ? a : b;
}

template <typename T>
void Test_driver() {
    // Vector<T> myVector(5);
}

int main() {
    // Test_driver<float>();
    cout << Max(1.0, 2.0) << endl;
    return 0;
}