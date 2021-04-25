#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>
using namespace std;

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