/*
 * @Author: your name
 * @Date: 2020-03-03 15:19:07
 * @LastEditTime: 2020-04-01 11:02:42
 * @LastEditors: Please set LastEditors
 * @Description: 元编程
 * @FilePath: /wanmen3/2.cpp
 */
// lambda算子
// 函数接收一个类型并返回一个类型, 而不是像之前一样接收一个值返回一个值
// 那么这个函数称为元函数

#include <iostream>
#include <map>
#include <string>
using namespace std;
/* template <typename T>
class Vector {
   public:
    using value_type = T;
    // 以后见到value_type默认为一个通用方法
    // using 相当与给了T一个别名value_type
}; */

template <typename C>
using Element_type = typename C::value_type;

template <typename Container>
// 元编程
void algo(Container &C) {
    Vector<Element_type<Container>> vec;
}

/* template <typename Key, typename Value>
class Map {
    // ...
}; */


// 使用using定义新的模板
template <typename Value>
using String_map = map<string, Value>;

int main() {
    
    String_map<int> m;
    m.insert(std::make_pair("1", 1));
    m.insert(std::make_pair("2", 2));

    for (auto x : m) {
        std::cout << "m.first: " << x.first << "  m.second: " << x.second
                  << std::endl;
    }
    return 0;
}
