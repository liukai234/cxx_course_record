#include <iostream>
using std::cout;
using std::endl;
using std::string;

struct User {
    // string s("hello"); // error cannot user () to init object
    string s{"hello"}; // that's ok
};

int main() {
    string s{"Hello"};
    decltype(s.size()) lowercase = 0; // decltype 类型指示符
    for(auto c : s) { if(islower(c)) { ++lowercase; } } // auto 类型说明符
    cout << lowercase << endl;
}
