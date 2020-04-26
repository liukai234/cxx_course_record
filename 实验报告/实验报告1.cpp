/*
 * @Author: your name
 * @Date: 2020-04-07 15:58:34
 * @LastEditTime: 2020-04-07 15:58:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/lib/实验报告1.cpp
 */


#include <iostream>
#include <string>

using namespace std;

class Teacher {
   public:
    Teacher(const string &name, const unsigned &age, const string &sex,
            const string &addr, const string &numb, const string &title);
    void display();

   protected:
    string name;
    unsigned age;
    string sex;
    string addr;
    string numb;
    string title;  // 职称
};
Teacher::Teacher(const string &name, const unsigned &age, const string &sex,
                 const string &addr, const string &numb, const string &title)
    : name{name}, age{age}, sex{sex}, addr{addr}, numb{numb}, title{title} {}

void Teacher::display() {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "sex: " << sex << endl;
    cout << "addr: " << addr << endl;
    cout << "numb: " << numb << endl;
    cout << "title: " << title << endl;
}

class Cadre {
   public:
    Cadre(const string &name, const unsigned &age, const string &sex,
          const string &addr, const string &numb, const string &post);
    void display();

   protected:
    string name;
    unsigned age;
    string sex;
    string addr;
    string numb;
    string post;  //职务
};

Cadre::Cadre(const string &name, const unsigned &age, const string &sex,
             const string &addr, const string &numb, const string &post)
    : name{name}, age{age}, sex{sex}, addr{addr}, numb{numb}, post{post} {}

void Cadre::display() {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "sex: " << sex << endl;
    cout << "addr: " << addr << endl;
    cout << "numb: " << numb << endl;
    cout << "post: " << post << endl;
}

class Teacher_Cadre : public Teacher, public Cadre {
   public:
    Teacher_Cadre(const string &name, const unsigned &age, const string &sex,
                  const string &addr, const string &numb, const string &title,
                  const string &post, const int &wages);
    void show();

   private:
    int wages;
};
Teacher_Cadre::Teacher_Cadre(const string &name, const unsigned &age,
                             const string &sex, const string &addr,
                             const string &numb, const string &title,
                             const string &post, const int &wages)
    : Teacher(name, age, sex, addr, numb, title),
      Cadre(name, age, sex, addr, numb, post),
      wages{wages} {}

void Teacher_Cadre::show() {
    Teacher::display();
    cout << "post: " << post << endl;
    cout << "wages: " << wages << endl;
}

bool test_driver() {
    string name = "张";
    unsigned age = 20;
    string sex = "男";
    string addr = "山西省";
    string numb = "15536002500";
    string title = "一";
    string post = "二";
    int wages = 100;
    // Teacher tch(name, age, sex, addr, numb, title);
    // tch.display();
    // cout << endl;
    // Cadre cad(name, age, sex, addr, numb, post);
    // cad.display();
    // cout << endl;
    Teacher_Cadre tcad(name, age, sex, addr, numb, title, post, wages);
    tcad.show();

    return true;
}

int main() {
    if (test_driver())
        cout << "test complete\n";
    else
        cout << "test error\n";
    return 0;
}
