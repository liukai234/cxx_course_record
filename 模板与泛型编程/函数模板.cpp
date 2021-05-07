// ../现代C++特性/函数指针.cpp
// 函数模板
#include <iostream>

using namespace std;

template <typename T> int compare(const T&, const T&);

void func(int (*) (const int &, const int &));
void func(int (*) (const string &, const string &));

int main() {
    int (*pf1) (const int &, const int &) = compare; // 定义函数指针pf并置空
    func(compare<int>);
}