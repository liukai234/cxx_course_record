#include <iostream>
using namespace std;

int main() {
    // 顶层const可以表示任意对象是常量：算术类型、类、指针等，底层const只与指针和引用等复合类型的基本类型部分有关
    // 对象的拷贝操作中，顶层const不受影响，但底层const的限制不能忽视
    // 一般来说，在底层const中，非常量可以转换为常量，反之则不行
    
    const char a = 'a'; // top-level const
    const char &aa = a; // low-level const bind to not-low-level const
    
    char b = 'b';
    const char *p = &a; // low-level const // char const *p
    char *const q = &b; // top-level const

    const char* const z = &b; // low and top level const

    p = &b;
    const char cc = 'c'; // top-level const

    // low-level const and not-low-level const trans to low-level const then is binded to low-level const
    const char &d = cc;

    cout << *p << " " << *q << endl;
    return 0;
}
