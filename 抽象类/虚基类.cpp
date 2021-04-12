// 虚基类
// [注] 虚基类并不是在声明基类是声明的,而是在声明派生类时, 指定继承方式时声明的
// class 派生类名 : virtual 继承方式 基类名

/*
 * 为了解决多继承时(类似菱形继承)的命名冲突和冗余数据问题，C++ 提出了虚继承，使得在派生类中只保留一份间接基类的成员
 * 在继承方式前面加上 virtual 关键字就是虚继承
 * 使用虚继承重新实现的菱形继承，这样在派生类 D 中就只保留了一份成员变量 m_a，直接访问就不会再有歧义了
 * 虚继承的目的是让某个类做出声明，承诺愿意共享它的基类
 * 其中，这个被共享的基类就称为虚基类（Virtual Base Class），本例中的 A 就是一个虚基类
 * 在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员
 */

// 菱形继承
// 间接基类A
class A{
protected:
    int m_a;
};

// 直接基类B
class B: virtual public A{  // 虚继承
protected:
    int m_b;
};

// 直接基类C
class C: virtual public A{  // 虚继承
protected:
    int m_c;
};

// 派生类D
class D: public B, public C{
public:
    /*
     * void seta(int a){ m_a = a; }  
     * 如果不使用虚继承的话会产生命名冲突，D不知道m_a来自B还是C，但是可以通过以下方法指定其路径来自A->B->D或A->C->D
     * void seta(int a){ B::m_a = a; }
     * void seta(int a){ C::m_a = a; }
     */
    void seta(int a){ m_a = a; }  //正确
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确
private:
    int m_d;
};

int main(){
    D d;
    return 0;
}