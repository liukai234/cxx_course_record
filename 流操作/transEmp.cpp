/*
 * @Description: format zen of python
 * @LastEditors: liukai
 * @Date: 2020-04-20 10:10:54
 * @LastEditTime: 2020-04-20 10:42:31
 * @FilePath: /C++课程学习记录/流操作/transEmp.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
// #include <strstream>
using namespace std;

int main() {
    char ch[200];
    string str;
    ifstream infile("input.txt", ios::in);
    if(!infile) { cerr << "open error" << endl; exit(1); } // cerr 不会计入缓冲区

    ofstream outfile("output.txt", ios::out);
    if(!outfile) { cerr << "open error" << endl; exit(1); }
    
    while(infile.peek() != EOF){
        infile.getline(ch, 200);
        outfile << "<font color=\"#e74c3c\">"; 
        for(int i = 0; ch[i] != 0; i++){
            if(ch[i] == '(') outfile << "//"; // do something 借助宽字符模式
            else if(ch[i] == ')') { /* nothing */ }
            else outfile << ch[i];
            if(ch[i] == '.') outfile << "</font>&nbsp;&nbsp;"; 
        }
        outfile << endl;
    }
    
    infile.close();
    outfile.close();
    return 0;
}