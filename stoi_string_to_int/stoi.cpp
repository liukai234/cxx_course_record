/*
 * @Author: your name
 * @Date: 2020-04-07 08:44:17
 * @LastEditTime: 2020-04-07 08:50:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/stoi_string_to_int/stoi.cpp
 */

#include <string>
#include <iostream>

using std::string;
using namespace std;

int main() {
    string str1 = "asq,";
    // int c = stoi(str1);    // 报异常
    // 只要有数字就不报异常，遇到其他字符停止
    string str2 = "123,12";
    int c = stoi(str2);  // ok
    cout << c << endl; // c = 123
}