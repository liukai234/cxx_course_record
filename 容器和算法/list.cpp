/*
 * @Author: your name
 * @Date: 2020-03-10 09:49:41
 * @LastEditTime: 2020-04-01 11:07:18
 * @LastEditors: Please set LastEditors
 * @Description: list 容器与多态的微妙关系
 * @FilePath: /wanmen_container/list.cpp
 */
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;
class Shape {
   public:
    Shape(int a_param) : a{a_param} {}

   private:
    int a;
};
// 对于容器来说 相比于容器中放一个基类来说, 放容器指针和只能指针是更好的选择

vector<Shape> vs;
vector<Shape*> vps;
// vector<unique_ptr<Shape> > vups;

template <typename T>
class Vec : public std::vector<T> {
   public:
    using vector<T>::vector;
    T& operator[](int i) { return vector<T>::at(i); }  // at具有边界检查的能力
};

struct Entry {
    string str;
    unsigned int num;
};

class book {
public:
    book(Entry &entry){// , list<Entry>::iterator p
        phone_book.push_back(entry);
        // phone_book.insert(p, entry);
        // phone_book.erase(p);
    }
    // map like key and key value
    // function One use for_each
    int get(string str) const{
        for(auto &x : phone_book){
            if(x.str == str){
                return x.num;
            }
        }
    }
    // second function use for-loop to get p-iterator(distance((list)phone_book, p))
    int get2(string str) const{
        for(auto p = phone_book.begin(); p != phone_book.end(); p ++){// The p's type
            cout << "p's type is : " << typeid(p).name() << endl; // 依赖库 typeinfo // typeif(var).name()
            if(p->str == str){
                return p->num;
            }
        }
        return 0; // not found
    }
   private:
    list<Entry> phone_book;
    // write as map<string, int> phone_book; 
    // map is Red-Black Tree  会根据first排序, 是一种自适应平衡树 set同理
    // 若不想排序, 可以借助hash table的set和map unordered_set unordered_map
    /* template<typename T>
    struct make_pair
    {
        T first;
        T second;
    }; */
    
};

int main() {
    list<int> intList{1, 2, 3, 4, 5};
    list<int>::iterator p = intList.begin();
    cout << "lst p: " << *p << endl;
    advance(p, 2);
    cout << "lst advance p: " << *p << endl;
    auto q =
        intList.end();  // 这里需要给q -- 当前List开始于begin(), 结束于< end()
    q--;
    cout << "lst end q:" << *q << endl;
    cout << "distancd(p & q): " << distance(p, q)
         << endl;  // 返回两个指针之间的距离
    iter_swap(p, q);
    for (auto& x : intList) {
        cout << x << " ";
    }
    cout << endl;


    Entry entry;
    entry.str = "test_str1";
    entry.num = 1;
    book *mybook = new book(entry);
    mybook->get2("test_str1");
    return 0;
}
