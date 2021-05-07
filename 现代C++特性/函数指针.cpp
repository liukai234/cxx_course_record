// 函数指针
#include <iostream>

using namespace std;

bool lengthCompare(const string &s1, const string &s2){
    if(s1.length() >= s2.length()) return true;
    else return false;
}

// 函数指针形参
string userLonger(const string &s1, const string &s2, bool (*pf) (const string &s1, const string &s2)) {
    if(pf(s1, s2)) { return s1; }
    else return s2;
}


// 函数指针返回值
// using GET_TYPE = bool (*)(const string &s1, const string &s2);
// GET_TYPE getLengthCompare() 声明
bool (*getLengthCompare())(const string &s1, const string &s2) {
    return lengthCompare;
}

// 尾置函数指针返回值
auto getLengthCompare2() -> bool (*)(const string &s1, const string &s2) {
    return lengthCompare;
}


int main() {
    bool (*pf) (const string &, const string &) = nullptr; // 定义函数指针pf并置空
    pf = lengthCompare;
    cout << userLonger(string("123"), string("12345"), pf) << endl;
    pf = getLengthCompare();
    cout << userLonger(string("123"), string("12345"), pf) << endl;
}