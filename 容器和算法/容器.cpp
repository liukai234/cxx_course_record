#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
/*
 * 容器：
 * vector：可变大小数组
 * deque：双端队列
 * list：双向列表
 * forward_list：固定大小数组
 * array、string：与vector类似的容器，但专门用来保存字符
 */
class A {
public:
    A(int i, string s):i_(i), s_(s) {}
    int i_;
    string s_;
    friend ostream &operator<<(ostream&, A&);
};

ostream &operator<<(ostream &os, A &a) { os << a.i_ <<  " " << a.s_ << endl; return os; }

int main() {
    vector<int> c{0, 1};
    auto iter = c.begin();
    /*
     * vector 在尾部之外的位置插入或删除元素很慢
     * but 以下是一个很优雅的操作，类似执行了push_front()的操作
     * [!!] insert 的返回值为迭代器，其指向刚插入的新元素
     */
    int append;
    stringstream ss(string("1 2 3"));
    while(ss >> append) {
        iter = c.insert(iter, append);
    }
    for(auto &i : c) { cout << i << " "; }
    cout << endl;

    for(auto &i : c) { cout << i << " "; }
    cout << endl;

    /*
     * 删除元素
     */
    for(iter = c.begin(); iter != c.end(); ++iter) {
        if(*iter == 1) break;
    }
    c.erase(iter);

    c.clear();
    for(auto &i : c) { cout << i << " "; }
    cout << endl;

    /*
     * 构造元素
     * push_front     emplace_front
     * insert         emplace
     * push_back      emplace_back
     */
    /*
     * () 认为是构造函数
     * {} 认为是列表初始化
     */
    vector<A> va{A(0, "0")};
    va.push_back(A(1, "1"));
    for(auto &i : va) { cout << i; }
}

/*
 * string 定义了两个额外的成员函数：append and replace
 * string 的搜索类函数：find、rfind、find_first_of、find_last_of、find_first_not_of、find_last_not_of
 */

/*
 * 容器适配器stack、queue、priority_queue
 * 适配器是一种机制，能使某种事物的行为看起来想另外一种事物一样
 * 一个容器适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型
 * 默认情况下，stack和queue是基于deque实现的，priority_queue是在vector基础上实现的
 */