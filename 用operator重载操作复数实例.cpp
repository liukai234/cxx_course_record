/*
 * @Author: your name
 * @Date: 2020-02-25 22:15:23
 * @LastEditTime: 2020-02-25 22:40:29
 * @LastEditors: Please set LastEditors
 * @Description: complex
 * @FilePath: /newclass/complex.cpp
 */

#include <iostream>
using namespace std;

// 重载运算符() [] -> 或赋值运算符 = 时,
// 运算符重载函数必须声明为类的成员函数

// - 的优先级高于 +=
// 运算符优先级
// C: https://www.cnblogs.com/panda1024/p/5497649.html
// C++: https://www.luogu.com.cn/blog/xukuan/cplusplus-operator-precedence

// 如果运算符重载为友元函数 a + b 为 operator+(a, b)
// 如果运算符定义为成员函数 a + b 为 a.operator+(b)

class complex {
   public:
    complex(double r, double i) : re{r}, im{i} {}
    complex(double r) : re{r}, im{0} {}
    complex() : re{0}, im{0} {}

    double real() const { return re; }
    double real(double d) { re = d; }
    // const关键字放于函数后面，表示该函数是一个常成员函数，在该函数内不能修改该类的成员变量
    // const关键字放于函数前面，表示该函数的返回值为常量，不可以修改
    double imag() const { return im; }
    double imag(double d) { im = d; }

    complex &operator+=(complex z) {
        re += z.re, im += z.im;
        return *this;
    }
    complex &operator-=(complex z) {
        re -= z.re, im -= z.im;
        return *this;
    }
    complex &operator*=(complex z) {
        int a = re, b = im, c = z.re, d = z.im;
        // (a+bi)(c+di)=(ac-bd)+(bc+ad)i
        re = a * c - b * d;
        im = b * c + a * d;
        return *this;
    }

    complex &operator/=(complex z) {
        int a = re, b = im, c = z.re, d = z.im;
        // (a+bi)(c+di)=(ac-bd)+(bc+ad)i
        re = (a * c + b * d) / (c * c + d * d);
        im = (b * c - a * d) / (c * c + d * d);
        return *this;
    }

    //为了访问私有成员, 必须以友元函数重载
    friend ostream &operator<<(ostream &, complex &);
    friend istream &operator>>(istream &, complex &);

   private:
    double re;
    double im;
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

ostream &operator<<(ostream &output, complex &c) {
    output << "(" << c.re << " + " << c.im << "i)";
}

istream &operator>>(istream &input, complex &c) {
    input >> c.re >> c.im;
    return input;
}

void test_driver() {
    complex a{1, 1};
    complex b{2, 2};
    // cin >> a >> b;
    complex c = -a;
    cout << " - " << a << " = " << c << endl;
    c = a + b;
    cout << a << " + " << b << " = " << c
         << endl;  // 重载为operator<<(cout, c);
    c = a - b;
    cout << a << " - " << b << " = " << c << endl;
    c = a * b;
    cout << a << " * " << b << " = " << c << endl;
    c = a / b;
    cout << a << " / " << b << " = " << c << endl;
    // cout << c.real() << " " << c.imag() << endl;
}

int main() {
    int a, b;
    a = 5, b = 6;  // 这种操作在C++中没得问题

    test_driver();
    return 0;
}