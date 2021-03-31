#include <iostream>
#include <list>
#include <sstream> /* istringstream 引用 */

using namespace std;

class NLComponent{
public:
    /*
     * cxx中通过让一个函数（无方法体，即无{}）等于0，来让他成为纯虚函数
     */
    virtual string getName() = 0;
    virtual NLComponent * clone() const = 0;
    /*
     * non-member functions 的虚化（operator<< etc.）：写一个虚函数做实际工作，再写一个什么都不做的非虚函数，只负责调用虚函数
     * 为了避免此安排带来的成本，可以将非虚函数inline化
     */
    virtual ostream& print(ostream &s) const = 0;
private:
};


class TextBlock : public NLComponent{
public:
    TextBlock(string initName):initName_(initName) {}
    virtual string getName() override { return "TextBlock: " + initName_; } /* 重载加上override */
    /*
     * clone 函数取决去拷贝copy复制函数的行为，与其行为一致
     */
    virtual TextBlock * clone() const override { return new TextBlock(*this); }
    virtual ostream& print(ostream &s) const override {
        s << "TextBlock: " + initName_ << endl;
        return s;
    }
    // 没有也可
    // friend ostream& operator<<(ostream &s, const NLComponent &c);
private:
    string initName_;
};


class Graphic : public NLComponent {
public:
    Graphic(string initName):initName_(initName) {}
    virtual string getName() override { return "Graphic: " + initName_; }
    virtual Graphic * clone() const override { return new Graphic(*this); }
    virtual ostream& print(ostream &s) const override {
        s << "Graphic: " + initName_ << endl;
        return s;
    }
    // friend ostream& operator<<(ostream &s, const NLComponent &c);
private:
    string initName_;
};

/*
 * ostream& operator<<的重载
 * 第一个参数是流，第二个参数是对象
 * 如果只有一个参数，那就为流
 * return: 作为参数传入的那个流，需要返回值是因为cout等本身就有返回，返回值可以用于其他操作
 */
inline ostream& operator<<(ostream &s, const NLComponent &c) {
    return c.print(s);
}

class NewsLetter {
public:
    NewsLetter(istream &str);
    NewsLetter(const NewsLetter& rhs);
    list<NLComponent*> getALL() { return components; }
private:
    list<NLComponent*> components;
    static NLComponent* readComponent(istream& str);
};

/*
 * 由readComponent产生一个新对象，并且视他读入的数据而定对象的类型
 * 其行为仿若constructor，而且可以产生不同类型的对象
 * 所以称为virtual constructor
 */
NLComponent * NewsLetter::readComponent(istream &str) {
    /*
     * 由输入类型来确定返回类型
     * return new TextBlock()
     * Or
     * return new Graphic()
     */
    int i = 0;
    str >> i;
    if(i == 1) { return new TextBlock("1"); }
    else { return new Graphic("0"); }
}

NewsLetter::NewsLetter(istream &str) {
    while(str) {
        components.push_back(readComponent(str));
    }
}

/*
 * virtual copy constructor 其行为取决去 copy constructor
 */
NewsLetter::NewsLetter(const NewsLetter &rhs) {
     for(list<NLComponent*>::const_iterator it = rhs.components.begin(); it != rhs.components.end(); ++it) {
         components.push_back((*it)->clone());
     }
}

int main() {
    /*
     * istringstream（引用头文件<sstream>） 通过 istringstream::rdbuf() 转换为istream
     */
    istringstream iss("1 1 0 1"); // [!!] 结尾的\0会被当作0
    istream is(iss.rdbuf());

    using typeALL = list<NLComponent*>;
    NewsLetter newsLetter(is);
    typeALL all = newsLetter.getALL();
    for(typeALL::iterator it = all.begin(); it != all.end(); ++it) {
        cout << *(*it);
    }
}