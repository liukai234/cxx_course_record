/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-17 14:05:43
 * @LastEditTime: 2020-04-17 15:21:10
 * @FilePath: /C++课程学习记录/流操作/iostream.cpp
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    // int ite = 10;
    // 当有cin时就已经将输入流全部读取完成了，以下的get和peek之不是在流中进行操作
    char ch[20];
    cin.ignore('a'); // 参数：忽略字符，中止字符 (指针向后移动)
    // cin.getline(ch, 20, '/'); // 参数：数组，读入长度，中止字符
    cout << ch << endl;
    return 0;
    while(!cin.eof()) {
        // --ite;
        c = cin.get(); // 从当前cin流中读取一个字符，cin流中就会减少一个字符(指针向后移动1个字符)
        if((c = cin.peek()) == 'a') // peek "观察" 观察当前cin的下一个字符，指针仍停留在原位置
            cout.put(c); cout << " : " << __LINE__ << endl; // cout.put输出字符型
    }
    cout << endl;
    return 0;
}