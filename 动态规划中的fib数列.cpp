/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-13 08:28:59
 * @LastEditTime: 2020-04-13 08:29:00
 * @FilePath: /C++课程学习记录/动态规划中的fib数列.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

unsigned long fib(unsigned long n) {
    static vector<unsigned long> memo = {0, 1};
    if(n < memo.size()) {
        return memo[n];
    } else {
        unsigned long temp = fib(n - 1) + fib(n - 2);
        memo.push_back(temp);
        return temp;
    }
}

int main(int args, char *argv[]){
    cout << fib(500) << endl;
    return 0;
}