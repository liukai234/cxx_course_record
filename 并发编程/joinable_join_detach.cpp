/*
 * @Author: your name
 * @Date: 2020-04-10 17:55:46
 * @LastEditTime: 2020-04-10 19:04:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/thread多线程/test.cpp
 */

// join()
/**
 * 一旦线程开始，我们要想等待线程完成，需要在该对象上调用join()
 * 双重join将导致程序终止
 * 在join之前我们应该检查显示是否可以被join,通过使用joinable()
*/

// detach()
/**
 * 这用于从父线程分离新创建的线程
 * 在分离线程之前，请务必检查它是否可以joinable，
 * 否则可能会导致两次分离，并且双重detach()将导致程序终止
 * 如果我们有分离的线程并且main函数正在返回，那么分离的线程执行将被挂起
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

void run(int count) {
    while (count-- > 0) {
        cout << count << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    thread t1(run, 10);
    cout << "main()" << endl;
    if(t1.joinable()) t1.join();
    // t1.detach(); // erroe 必须检查是否可以joinable()
    if(t1.joinable()) t1.detach();
    cout << "main() after" << endl;
    return 0;
}