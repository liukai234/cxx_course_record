/*
 * @Description: 字符串流
 * @LastEditors: liukai
 * @Date: 2020-04-17 15:24:51
 * @LastEditTime: 2020-04-18 16:55:20
 * @FilePath: /C++课程学习记录/流操作/strstream.cpp
 */

#include <strstream>
#include <iostream>

using namespace std;

int main() {
    char ch[10] = {50, 51, 52};
    char ch2[10];
    istrstream strin(ch, sizeof(ch));
    for(int i = 0; i < 10; i++) { strin >> ch2[i]; }
    // ostrstream strout(ch2, sizeof(ch2));
    cout << ch2 << endl;
    return 0;
}