/*
 * @Author: your name
 * @Date: 2020-02-27 15:41:03
 * @LastEditTime: 2020-04-01 11:04:00
 * @LastEditors: Please set LastEditors
 * @Description: 有关类的实例
 * @FilePath: /wanmen3/EmpForClass.java
 */

#include <iostream>
#include <string>
using namespace std;

class Vector{
public:
    // 参数列表
    Vector(initializer_list<double> list)
     :sz{list.size()},
      elem{new double[sz]}
    {
        copy(list.begin(), list.end(), elem);
    }

    double& operator[](size_t i){
        return elem[i];
    }

    size_t size(){
        return sz;
    }

    ~Vector(){
        delete[] elem;
    }

    // 复制拷贝函数
    Vector(const Vector &other)
     :sz{other.sz},
      elem{new double[sz]}
    {
        for(size_t i = 0; i < sz; i ++){
            elem[i] = other.elem[i];
        }
    }
private:
    size_t sz;
    double *elem;
};

// 纯接口类, 只要该类包含一个纯虚函数pure virtual function,则该类为纯接口类pure virtual class 
class Container{
public:
    // 纯虚函数
    // 纯虚函数目的在于定义好接口, 例如这里其他继承的函数必须和纯虚函数中的完全相同, 减少错误, 例如这个double &operator[]
    virtual double &operator[](size_t i) = 0;
    virtual size_t siz() = 0;
    ~Container(){}
};

class Vector_container : public Container{
public:
    Vector_container(initializer_list<double> vec)
     : v{vec}
    {
        // copy(vec.begin(), vec.end(), v.operator[]);
    }
    virtual ~Vector_container() = default;
    virtual double &operator[](size_t i){
        return v.operator[](i);
    }
    virtual size_t siz(){
        return v.size();
    }
private:
    Vector v;
};

#include <list>
// 包含list模板, 用initializer_list 初始化list
class List_container : public Container{
public:
    List_container(initializer_list<double> vec)
     : v{vec}
    {
        // copy(vec.begin(), vec.end(), v);
    }
    virtual ~List_container() = default;
    virtual double &operator[](size_t i){
        // 对list的使用方法
        for(auto &x : v){
            if(i == 0) return x;
            i --;
        }
        // ? i == 0没有返回, 捕获异常
        throw out_of_range("list container");
    }
    virtual size_t siz() override{ // 表明函数是继承来的
        return v.size();
    }
private:
    list<double> v;
};


void display(Container &c){
    for(size_t i = 0; i < c.siz(); i++){
        cout << c.operator[](i) << " ";
    }
    cout << endl;
}

void Test_deiver(){
    Vector_container vc = {0, 1, 2, 4};
    display(vc);
    List_container lc = {9, 8, 7, 6};
    display(lc);
}

int main() {
    Test_deiver();
    return 0;
}