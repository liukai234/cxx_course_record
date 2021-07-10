#include <iostream>

using namespace std;

// 引用返回左值
// 调用一个返回引用的函数得到左值，其他返回类型得到右值
// 可以像使用其他左值那样来使用返回引用的函数的调用
string &func(string &s) { return s; }

int main() {
    string s = "123456";
    func(s) = "654321";
    cout << s << endl;
}
