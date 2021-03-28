#include <iostream>
using namespace std;

class Rational {
public:
    /*explicit*/ Rational(int a, int b = 0) : a_(a), b_(b){}
    // explicit 显式类型转换，用于template的重载运算符
    
    bool operator==(const Rational& rational) const {
        return this->a_ == rational.a_;
    }

    /*operator double() const {
        return (double)a_/b_;
    };*/

    /*
     * good: 定义一个asDouble方法
     * 避免在没有重载输出运算符时调用double()
     */
    double asDouble() const { return (double)a_/b_; }

private:
    int a_, b_;
};

void driver() {
    Rational rational(1, 2);
    Rational rational1(2, 3);
    /*
     * 如果这里没有一个良好的重载输出函数的化，编译器会想办法调用
     * Rational::operator double() const来转换rat让其输出
     * 这可能会导致预期的错误，应当避免隐式的类型转换
     */
    // cout << rational;
    cout << rational.asDouble();
    // if(rational < rational1) cout << "\nrat < rat1";

    if(rational == rational1) cout << "\nrat == rat1";
    else cout << "\nrat != rat1";
}

int main() { driver(); }
