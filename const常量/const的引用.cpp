// 引用类型必须与其所引用对象的类型一致
// 例外：1. 初始化常量引用时允许用任意表达式作为初始值 2，对const引用一个非const的对象

int main() {
    const int &b = 10 + 6; // 例外1
    int a = 2;
    const int &aa = a; // 例外2
    a = 3;
    // aa = 4; // error
}
