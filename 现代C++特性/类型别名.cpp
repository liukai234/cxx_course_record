int main() {
    typedef int userInt;
    using userInt2 = int;
    using userIntPointer = int*;
    
    int b = 2;
    const userIntPointer a = &b; 
    // 不要把userIntPointer的定义代入展开 这里const修饰的是userIntPointer整个指针
    int c = 3;
    // a = &c; // error
    *a = 3;
}
