/*
 * 关联容器
 * 有序
 * map
 * set
 * multimap
 * multiset
 * 无序
 * unordered_map
 * unordered_set
 * unordered_multimap
 * unordered_multiset
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <map>


using namespace std;

int main() {
    pair<string, string> p1("0", "0");
    cout << p1.first << " " << p1.second << endl;
    p1 = make_pair("1", "1");
    cout << p1.first << " " << p1.second << endl;

    map<string, string> m1;
    m1.insert(p1);
    /*
     * map下标 operator[] 当没有一个元素时将其加入容器
     *        at()        当没有时抛出out_of_range异常
     */

    m1["0"] = string("123");
    cout << m1.at("0") << endl;
    
    // 参数列表插入
    m1.insert({"2", "2"});
    m1.insert(make_pair("3", "3"));

    for_each(m1.begin(), m1.end(), [](pair<string, string> x){ cout << x.first << " " << x.second << endl; });
}