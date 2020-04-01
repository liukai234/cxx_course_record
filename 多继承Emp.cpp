/*
 * @Author: your name
 * @Date: 2020-03-26 09:37:54
 * @LastEditTime: 2020-04-01 10:58:14
 * @LastEditors: Please set LastEditors
 * @Description: 多继承中的二义性问题解决
 * @FilePath: /test/test.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Teacher {
   public:
    Teacher(string nam, int a, string s, string add, string n, string t);
    void display();

   protected:
    string name;
    int age;
    string sex;
    string addr;
    string number;
    string title;  // 职称
};
Teacher::Teacher(string nam, int a, string s, string add, string n, string t)
    : name{nam}, age{a}, sex{s}, addr{add}, number{n}, title{t} {}
void Teacher::display() {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "sex: " << sex << endl;
    cout << "addr: " << addr << endl;
    cout << "number: " << number << endl;
    cout << "title: " << title << endl;
}

class Cadre {
   public:
    Cadre(string nam, int a, string s, string add, string n, string t);
    void display();

   protected:
    string name;
    int age;
    string sex;
    string addr;
    string number;
    string post;  // 职务
};
Cadre::Cadre(string nam, int a, string s, string add, string n, string t)
    : name{nam}, age{a}, sex{s}, addr{add}, number{n}, post{t} {}
void Cadre::display() {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "sex: " << sex << endl;
    cout << "addr: " << addr << endl;
    cout << "number: " << number << endl;
    cout << "post: " << post << endl;
}

class Teacher_Cadre : public Teacher, public Cadre {
   public:
    Teacher_Cadre(string nam, int a, string s, string add, string n, string t,
                  string t_post, float w);
    void show();

   private:
    float wages;
};
Teacher_Cadre::Teacher_Cadre(string nam, int a, string s, string add, string n,
                             string t, string t_post, float w)
    : Teacher(nam, a, s, add, n, t),
      Cadre(nam, a, s, add, n, t_post),
      wages(w){};
void Teacher_Cadre::show() {
    Teacher::display();
    cout << "post: " << post << endl;
    cout << "wages: " << wages << endl;
};

int main() {
    Teacher_Cadre tcadre1("Zhang", 24, "female", "Shanghai", "155", "Teacher",
                          "org", 8000.01);
    tcadre1.show();
    return 0;
}