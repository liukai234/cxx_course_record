/*
 * @Author: your name
 * @Date: 2020-03-10 20:55:45
 * @LastEditTime: 2020-03-12 10:54:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen_container/algorithm.cpp
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

/* struct Entry {
    string str;
    int num;
};


list<Entry> f(vector<Entry> &vec) {
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res));
    // append to current res;
    return res;
}

bool has_c(const string &s, char c) {
    auto p = find(s.begin(), s.end(), c);
    if (p != s.end) {
        return true;
    } else {
        return false;
    }
}

bool has_c(const string &s, char c) {
    return find(s.begin(), s.end(), c) != s.end();
}
 */
void trans() {
    vector<string> quote{"This", "is", "a", "C++", "class"};
    vector<string> res;
    // algorithm 中transform 和 for_each的使用
    transform(begin(quote), end(quote), back_inserter(res),
              [](const string &word) { return "<" + word + ">"; });
              // 称为lambda表达式
    for_each(begin(res), end(res),
             [](const string &word) { cout << word << endl; });
}

int main() {
    // sort(iter begin, iter end) // 迭代器起始地址
    // unique_copy(T1 begin, T1 end, T2 begin)
    // 可以将vector拷贝到list或queue中
    // 将T1中的内容拷贝到T2中

    /* bool operator<(const Entry &x, const Entry &y){
        return x.name < y.name;
    } */
    trans();
    // lambda 表达式
    string str = "testing";
    // cxx 14 lambda 类型推导
    auto autopush = [](const auto &x) { return x * x; };
    // 在lambad前的方括号中是外部变量访问方式说明符, = can be read  &can be modified
    auto qouit = [=, &str](const int &value) { cout << str; str = "modify"; return value * value; }; // CLASS STRUCT LAMBAD + ;
    cout << qouit(10) << endl;
    cout << autopush(10.10) << endl;
}