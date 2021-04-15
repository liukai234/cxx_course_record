/*
 * 左值引用和右值引用
 */

#include <iostream>

using namespace std;


int main() {
    int a = 5;
    int &b = a;
    cout << b;
    int &&c = 5 + 2;
    cout << c;
}