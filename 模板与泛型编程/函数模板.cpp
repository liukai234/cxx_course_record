// ../现代C++特性/函数指针.cpp
// 函数模板
// 函数指针
#include <iostream>

using namespace std;

template <typename T> int compare(const T&, const T&) {
    return 0;
}

void func(int (*) (const int &, const int &)) {
    // dosomething
}
void func(int (*) (const string &, const string &)) {
    // dosomething
}

// pf1 中参数的类型决定了T的模板实参的类型，如果不能从函数指针类型确定模板参数则产生错误
int (*pf1) (const int &, const int &) = compare;

int main() {
    func(compare<int>);
    func(pf1);
}