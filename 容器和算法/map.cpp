/*
 * @Author: your name
 * @Date: 2020-03-10 18:10:25
 * @LastEditTime: 2020-03-11 15:11:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edits
 * @FilePath: /wanmen_container/map.cpp
 */

#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
// 如果要排序使用map, 如果不排序的话unordered是更好的选择
int main(){
    unordered_map<string, int> mapWorld;// test unordered_map // 依赖库unordered_map
    // 按照树的标准来插入 输出时是先序遍历(左 - 中 - 右)
    mapWorld.insert(make_pair("earth", 0));
    mapWorld.insert(make_pair("water", 1));

    mapWorld.insert(make_pair("fire", 2));
    for(auto p : mapWorld){
        cout<< p.first << p.second << endl;
    }
    
    

}