#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

/*
 * lambda
 * [capture](parameter list) -> return type { function body };
 * 捕获列表   参数列表             返回值类型      方法体
 * 1. 值捕获时[a]，与参数不同，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝
 *    可变lambda：可以通过参数列表首加上mutable来改变值拷贝参数的值，`auto f = [v1]()mutable{return ++v1;};`
 *    引用捕获[&a]
 *    隐式捕获列表[=] or [&]
 * 2. 使用尾置返回类型定义lambda的返回类型
 *    [](int i) -> int {if(i < 0) return -i; else return i;};
 */

int main() {
    vector<int> v{0, 1, 2, 3};
    /*
     * 需要lambda的一个场景
     * find_if接受一元谓词，当想要得到大于某个值时，没有办法传递给它第二个参数表示长度
     * 为此引入lambda表达式
     * 谓词是一个可调用的表达式，其返回结果是一个能用作条件的值
     * 标准库算法使用的谓词分为两类：一元谓词和二元谓词，即一个参数和两个参数
     */

    auto start = find_if(v.begin(), v.end(), [](int x){ return x >= 2; });
    for_each(start, v.end(), [](int x){ cout << x << " "; });
    
    return 0;
}