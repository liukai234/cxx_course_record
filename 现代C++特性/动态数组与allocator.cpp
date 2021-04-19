#include <iostream>
#include <memory>

using namespace std;

int main() {
    const int n = 5;
    // 存在的问题：初始化的n个空的string，但是有的可能永远不会用到
    auto *p = new string[n];

    // 将内存分配和构造分离开，提供一种类型感知的内存分配方法，它分配的内存是原始的、未构造的
    allocator<string> alloc;
    // 分配n个未未初始化的string
    auto p1 = alloc.allocate(n);
    // 使用alloc返回的内存必须用construct构造对象，使用未构造的内存，请行为是未定义的
    auto p2 = p1;
    alloc.construct(p2, "alloc.construct p2");
    cout << *p2;
    // 用完对象后，必须对每个构造元素调用destroy来销毁他们
    alloc.destroy(p2);
}