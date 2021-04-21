/*
 * @Author: your name
 * @Date: 2020-04-07 08:16:14
 * @LastEditTime: 2020-04-07 19:25:04
 * @LastEditors: Please set LastEditors
 * @Description: decltype (expression) 推导出表达式类型
 * @FilePath: /C++课程学习记录/decltype.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

// 泛型编程中结合auto，用于追踪函数的返回值类型
template <typename T>
auto multiply(T x, T y) -> decltype(x * y) {  // 指明返回值的类型
    return x * y;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    vector<int> vec(nums, nums + 4);  // 数组加入向量中
    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
    cout << endl;

    // decltype配合using使用
    using nullptr_t = decltype(nullptr);
    nullptr_t nu;
    int* p = NULL;
    if (p == nu) cout << "NULL" << endl;

    // decltype配合typedef使用
    // vector<int>::iterator it;
    typedef decltype(vec.begin()) vectype;

    for (vectype i = vec.begin(); i != vec.end(); i++) cout << *i << " ";
    cout << endl;

    /**
     * 匿名结构体
     */
    struct {
        int d;
        double b;
    } anon_s;

    decltype(anon_s) as;  // 定义了一个上面匿名的结构体

    cout << multiply(11, 2) << endl;
    // decltype(f()) sum = x;// sum的类型就是函数f的返回值类型。
    // 在这里编译器并不实际调用f函数，而是分析f函数的返回值作为sum的定义类型。

    return 0;
    /* 
     * 更简洁的例子
     * auto 的类型是根据等于号右边得到的
     * decltype不需要初值
       auto a = 5;
      
       1. decltype(a) c;
       2. using type = decltype(a); type d = 5;
     */
}
