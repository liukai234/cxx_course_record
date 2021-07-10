// 引用类型必须与其所引用对象的类型一致，普通引用只能绑定在对象上
// 例外：1. 初始化常量引用（const）时允许用任意表达式作为初始值 2，对const引用一个非const的对象

int main() {
    // int &i = 2; // error
    const int &b = 10 + 6; // 例外1（常量表达式）
    const int &c = b;

    int a = 2;
    // int & &d = a; // error 引用的引用
    const int &aa = a; // 例外2
    a = 3;
    // aa = 4; // error
}
