/*
 * @Author: your name
 * @Date: 2020-03-10 18:21:50
 * @LastEditTime: 2020-03-10 18:25:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen_container/set.cpp
 */
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> setworld;
    setworld.insert(1);
    setworld.insert(3);
    setworld.insert(2);
    // map order is 1 2 3
    // unordered not to sort
    for(auto x : setworld){
        cout << x << endl;
    }
    return 0;
}