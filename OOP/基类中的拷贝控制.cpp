/*
 * 拷贝控制操作有：
 * 1. 拷贝构造函数
 * 2. 拷贝赋值运算符
 * 3. 移动构造函数
 * 4. 移动赋值运算符
 * 5. 析构函数
 */

/*
 * 这里要明白的一些概念
 * 浅拷贝 shallow copy
 * 深拷贝 deep copy
 * 拷贝构造函数 A(const A& a)
 * 赋值函数 A& operator=(const A& a)
 * 移动拷贝构造函数 A(A && a)            使用时 A b(std::move(a));
 * 移动赋值函数 A& operator=(A && a)    使用时 A b; b = std::move(a);
 * // 移动即要清空原对象的内容（这里的移动是之前学习的std::move）
 */

/*
 * 基类中的拷贝控制的法则：
 * 浅拷贝会对自动合成的造成灾难，所以需要自定义某些拷贝控制操作
 * 如果一个类没有定义所有这些拷贝控制成员，编译器会自动为它定义缺失的操作（移动操作是特例）
 * [!!] 当一个类没有定义任何版本的拷贝控制成员时，且所有资源可被移动构造或移动赋值时，编译器才会为其合成移动构造函数或移动赋值运算符
 *
 * 有析构函数应该有拷贝构造函数和拷贝赋值运算符（有外部资源需要被释放，则需要深拷贝）
 * 有拷贝构造函数和拷贝赋值运算符不一定有析构函数（例如需要生成一个独一无二的值）
 */

/*
 * 移动而非拷贝对象会大幅提升性能
 * 虽然不能直接将一个右值引用直接绑定到一个左值上，但使用 std::move() 可以显式的将一个左值转换为对应的右值引用类型
 * int &&rr = std::move(rr1) // 调用std::move() 就意味着除了销毁或赋值它，不再使用它
 * 由于移动操作窃取资源，通常不分配任何资源，它不应抛出异常 noexcept
 *
 * 合成的移动操作
 * 如果一个类定义了自己的拷贝构造函数或拷贝赋值运算符，编译器不会为它合成移动构造函数和移动赋值运算符
 * 同理一个类定义了自己的移动构造函数或移动赋值运算符，编译器不会为它合成拷贝构造函数和拷贝赋值运算符
 * 如果一个类没有移动操作，通过正常的函数匹配，类会使用对应的拷贝操作来代替移动操作（用拷贝操作代替移动操作几乎总是安全的）
 */

/*
 * A (const A&other)
 * 在C++中，3种对象需要复制，此时拷贝构造函数会被调用
 * 1）一个对象以值传递的方式传入函数体
 * 2）一个对象以值传递的方式从函数返回
 * 3）一个对象需要通过另一个对象进行初始化
 */

#include <iostream>

using namespace std;

class Base {
public:
    Base(int i, string &s):i(i), s(s){}

    // 手动对所有资源进行拷贝，包括指针和内置类型
    Base(const Base &b) { this->i = b.i; this->s = b.s; cout << "Base copy ctor\n"; }

    // 如果一个类没有定义所有这些拷贝控制成员，编译器会自动为它合成缺失的操作，如这里未定义operator=也会自动合成
    Base &operator=(const Base &b) { this->i = b.i; this->s = b.s; cout << "Base copy operator=\n"; return *this; }

    // 如果一个类定义了自己的拷贝构造函数或拷贝赋值运算符，编译器不会为它合成移动构造函数和移动赋值运算符
    // 根据参数匹配会选择对应的拷贝函数
    Base(Base &&b) noexcept { this->i = b.i; this->s = b.s; b.i = 0; b.s = ""; cout << "Base move ctor\n"; } // [!!] 在这里不能将 string 置空
    Base &operator=(Base &&b) noexcept { this->i = b.i; this->s = b.s; b.i = 0; b.s = ""; cout << "Base move operator=\n"; return *this; }

    ~Base(){ cout << "dtor\n"; }

    // 对内置类型的移动是没有意义的
    // Clang-Tidy: Std::move of the variable 'b' of the trivially-copyable(平凡的可复制的) type 'Base' has no effect; remove std::move()
    int i;
    string s;
};

int main() {
    string s("string");
    Base b(1, s);
    Base b2 = std::move(b); // 移动构造 // 之后不应再次使用b，调用std::move() 就意味着除了销毁或赋值它，不再使用它
    b = b2; // 拷贝构造 // 对 b 赋值
    cout << "d.s: " << b2.s << " b.s: " << b.s << endl; 

    // 拷贝构造函数，用a来初始化b
    // A b(a); 或 A b = a;

    // 拷贝赋值运算符，b已经初始化，使用a来给b赋值
    // A b; b = a;
    
    // 移动构造函数，用a来初始化b，之后清空a
    // A b(std::move(a)); 或 A b = move(a); // 将左值a显式的转换为右值std::move(a)
    
    // 移动赋值运算符，b已经初始化，使用a来给b赋值，之后清空a
    // A b; b = std::move(a);

}

/*
 * 值得一提的是基类中的成员的拷贝控制情况会影响到基类中的拷贝控制情况
 */