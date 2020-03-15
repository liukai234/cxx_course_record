/*
 * @Author: your name
 * @Date: 2020-02-23 11:19:15
 * @LastEditTime: 2020-02-23 14:03:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen2/fib.cpp
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