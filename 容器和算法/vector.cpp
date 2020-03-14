/*
 * @Author: your name
 * @Date: 2020-03-03 20:36:44
 * @LastEditTime: 2020-03-11 15:12:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen3/.vscode/vector.cpp
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int, int> vecInt;

    vecInt.push_back(42);
    vecInt.push_back(42);
    vecInt.push_back(42);

    /* cout << "size: " << vecInt.size() << endl;
    cout << "capacity: " << vecInt.capacity() << endl;

    vector<int>::iterator iter = vecInt.begin();

    while(iter != vecInt.end()) {
        cout << "value of vecInt: " << *iter << endl;
        ++ iter;
    } */

    for(auto &x : vecInt){
        cout << x << endl;
    }
    
    return 0;
}