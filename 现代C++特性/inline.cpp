#include <iostream>

using namespace std;

// 内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求
inline const string &
shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

inline string &
shorterString(string &s1, string &s2) {
    auto &r = shorterString(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string&>(r);
}

int main(int argc, char *argv[]) {
    string s1 = "123";
    string s2 = "456";
    shorterString(s1, s2);
    shorterString("123", "456");
}