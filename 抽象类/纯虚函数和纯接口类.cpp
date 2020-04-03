/*
 * @Author: your name
 * @Date: 2020-02-27 15:41:03
 * @LastEditTime: 2020-04-03 09:47:08
 * @LastEditors: Please set LastEditors
 * @Description: 纯虚函数和 纯接口类/抽象类
 * @FilePath: /wanmen3/EmpForClass.java
 */

#include <iostream>
#include <string>

using namespace std;

class Vector {
   public:
    // 参数列表
    Vector(initializer_list<double> list)
        : sz{list.size()}, elem{new double[sz]} {
        copy(list.begin(), list.end(), elem);
    }

    double &operator[](size_t i) { return elem[i]; }

    size_t size() { return sz; }

    ~Vector() { delete[] elem; }

    // 复制拷贝函数
    Vector(const Vector &other) : sz{other.sz}, elem{new double[sz]} {
        for (size_t i = 0; i < sz; i++) {
            elem[i] = other.elem[i];
        }
    }

   private:
    size_t sz;
    double *elem;
};

// 抽象类/纯接口类, 只要该类包含一个纯虚函数pure virtual
// function,则该类为纯接口类pure virtual class
class Container {
   public:
    // 纯虚函数: 没有函数体的虚函数
    // 纯虚函数目的在于定义好接口,
    // 例如这里其他继承的函数必须和纯虚函数中的完全相同, 减少错误,
    // 例如这个double &operator[]
    virtual double &operator[](size_t i) = 0;
    virtual size_t siz() = 0;
    ~Container() {}
};

class Vector_container : public Container {
   public:
    Vector_container(initializer_list<double> vec) : v{vec} {
        // copy(vec.begin(), vec.end(), v.operator[]);
    }
    virtual ~Vector_container() = default;
    /*抽象类中：在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能使用纯虚函数
      如果一个类从抽象类派生而来，"
      它必须实现了基类中的所有纯虚函数，才能成为非抽象类 " */
    //   如果我们不在派生类中覆盖纯虚函数，那么派生类也会变成抽象类。
    virtual double &operator[](size_t i) { return v.operator[](i); }
    virtual size_t siz() { return v.size(); }

   private:
    Vector v;
};

class List_container : public Container {
   public:
    List_container(initializer_list<double> vec) : v{vec} {
        // copy(vec.begin(), vec.end(), v);
    }
    virtual ~List_container() = default;
    virtual double &operator[](size_t i) { return v.operator[](i); }
    virtual size_t siz() { return v.size(); }

   private:
    Vector v;
};

void display(Container &c) {
    for (size_t i = 0; i < c.siz(); i++) {
        cout << c.operator[](i) << " ";
    }
    cout << endl;
}

void Test_deiver() {
    // 抽象类只能作为基类来派生新类使用，不能创建抽象类的对象,抽象类的指针和引用->由抽象类派生出来的类的对象！
    // Container c1; // error 抽象类，不能创建对象
    Container *c1;  // ok 可以定义抽象类的指针
    // Container *c1 = new Container; // error,A是抽象类，不能创建对象
    Container *bp = new List_container(
        {1, 2});  // 抽象类的指针和引用 -> 由抽象类派生出来的类的对象
    // display(*bp);
    Vector_container vc = {0, 1, 2, 4};
    display(vc);
    List_container lc = {9, 8, 7, 6};
    display(lc);
}

int main() {
    Test_deiver();
    return 0;
}