#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <initializer_list>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

using std::initializer_list;

// 与vector不同的是init_list中的值永远是常量值
int func(initializer_list<string> lst) {
    lst.size();
    for(auto x : lst) { cout << x << endl; }
    return 0;
}

int main() {
    func({"123", "456", "789"});
}
