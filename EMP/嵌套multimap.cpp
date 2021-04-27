#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>
using namespace std;

/*
 * 由于map和set（以及对应的无序类型）包含不重复的关键字，因此插入一个已存在的元素对容器没有任何影响
 * vector<int> ivec{2,4,6,8,2,4,6,8};
 * set<int> set2;
 * set2.insert(ivec.cbegin(), ivec.cend()}; // set2.size()=4
 * set2.insert({1,3,5,7,1,3,5,7}) // set2.size=8
 * 但multimap和multiset可以有多个相同的关键字
 */

class Base {
public:
    Base(string name):name_(name){}
    void init();
    string find(string outer, char inner);
    
private:
    string name_;
    multimap<char, string> inside;
    multimap<string, multimap<char, string>> outside;
};

void Base::init() {
    inside.insert(make_pair('1', "1"));
    inside.insert(make_pair('2', "2"));
    inside.insert(make_pair('3', "3"));
    inside.insert(make_pair('4', "4"));
    for_each(inside.begin(), inside.end(), [](pair<char, string>p) { cout << p.first << " " << p.second << " "; });
    cout << endl;

    outside.insert(make_pair("string1", inside));
    outside.insert(make_pair("string2", inside));
    for_each(outside.begin(), outside.end(), [](pair<string, multimap<char, string>> p) { cout << p.first << " " << p.second.find('1')->second << " "; });
    cout << endl;
    return;
}

/* Emp for find */
string Base::find(string outer, char inner) {
    return outside.find(outer)->second.find(inner)->second;
}

int main(int argv, char *argc[]) {
    Base b("Base");
    b.init();
    cout << "find: "
         << b.find("string1", '2')
         << endl;
    return 0;
}