/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-17 14:57:20
 * @LastEditTime: 2020-04-17 20:12:21
 * @FilePath: /C++课程学习记录/流操作/fstream.cpp
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    char ch[20];
    ifstream infile("input.txt", ios::in);
    if(!infile) {cerr << "open error" << endl; exit(1);} // cerr 不会计入缓冲区
    infile.getline(ch, 20);
    infile.close();

    ofstream outfile("output.txt", ios::out);
    if(!outfile) {cerr << "open error" << endl; exit(1);}
    outfile << ch;
    outfile.close();
    return 0;
}