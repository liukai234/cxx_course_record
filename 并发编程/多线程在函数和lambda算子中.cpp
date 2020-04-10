/*
 * @Author: your name
 * @Date: 2020-04-10 17:28:24
 * @LastEditTime: 2020-04-10 18:50:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/thread多线程/intro.cpp
 */

#include <iostream>
#include <thread> // 线程库 编译时要加 -pthread 参数
#include <chrono> // hrono 时钟库，以各种精度跟踪时间的类型的灵活汇集

using namespace std::chrono;
using namespace std;

using ull = unsigned long long;
ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i)
        if ((i & 1) == 0)
            EvenSum += i;
}

void findOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i)
        if ((i & 1) == 1)
            OddSum += i;
}

int main() {

    ull start = 0, end = 1900000000;

    // 引入线程t1, t2
    auto startTime = high_resolution_clock::now(); // 高分辨率时钟
    // findOdd(start, end); // 寻找奇数
    // findEven(start, end); // 寻找偶数

    // std::thread t1(findOdd, start, end);
    // 或者将t1线程的 定义语句和函数 利用lambda算子合并
    std::thread t1([](int start, int end){int i = 0; for(int i = start; i < end; i ++) { if(i & 1 == 1) OddSum += 1; }}, start, end);
    t1.join();
    
    std::thread t2(findEven, start, end);
    t2.join();
    
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "EvenSum = " << EvenSum << endl;
    cout << "OddSum = " << OddSum << endl;
    cout << "duration = " << duration.count() / 1000000 << endl;
    return 0;
}
