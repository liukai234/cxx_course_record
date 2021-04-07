#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
/*
 * 泛型算法
 * 1. 只读算法
 * find
 * accumulate() // 需引用头文件 numeric (数字)
 * equal
 * 2. 写容器元素的算法
 * fill
 * fill_n
 * copy
 * replace 
 * replace_copy
 * sort
 * unique
 */
int main() {
    vector<int> v{0, 1, 2, 3};
    int findval = 2;
    vector<int>::iterator result = find(v.begin(), v.end(), findval); // 返回值是一个迭代器
    fill(v.begin(), v.end(), 0); // 将给定的值赋予序列范围中的每个元素
    fill_n(v.begin(), v.size() / 2, 0); // 将给定的值赋予序列范围中的每个元素
    replace(v.begin(), v.end(), 0, 111); // 第三个参数将搜索到的值替换为第四个
    for(auto x : v) { cout << x << " "; } cout << endl;
    /*
     * 对容器中所有元素求和，第三个参数的类型决定了函数中使用哪个加法运算符以及返回值的类型
     */
    int sum = accumulate(v.begin(), v.end(), 0);
    vector<string> v2{"123", "456", "789", "0"};
    string str = accumulate(v2.begin(), v2.end(), string("")); // "" is const char *, not string

    /*
     * 插入迭代器
     * 当通过一个插入迭代器赋值时，一个与赋值号右侧值相等的元素被加入到容器中
     */
    auto it = back_inserter(v2);
    *it = "12306";
    *it = "123";
    *it = "456";
    for(auto x : v2) { cout << x << " "; } cout << endl;

    /*
     * 拷贝算法 copy
     * 拷贝前必须保证目标容器的大小至少大于原始容器的大小
     */
    vector<string> v3(v2.size(), "");
    copy(v2.begin(), v2.end(), v3.begin()); // 第三个参数是目标迭代器

    /*
     * 重排容器
     */


    // 对v3进行排序 并清除v3中的重复元素 unique返回一个指向不重复值范围末尾的迭代器
    sort(v3.begin(), v3.end());
    auto end_unique = unique(v3.begin(), v3.end()); // 求unique后，被安排在末尾的重复元素的值是没有意义的
    // [!!] 单独使用erase调整大小，算法绝对不会改变容器的大小
    v3.erase(end_unique, v3.end());
    for(auto x : v3) { cout << x << " "; } cout << endl;



    return 0;
}