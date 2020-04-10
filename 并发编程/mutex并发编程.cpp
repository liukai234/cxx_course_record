/*
 * @Author: your name
 * @Date: 2020-04-10 19:05:51
 * @LastEditTime: 2020-04-10 19:18:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/thread多线程/test.cpp
 */

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int sum = 0; //shared

mutex m; // 与 lock unlock 成对使用

/*
mutex对象是一个lockable的对象，当关键区域需要被互斥访问的时候被用来当作信号
调用该函数后，调用函数会锁定mutex，在有些情况下调用函数会阻塞。
1、如果mutex当前没有被任何其他线程locked，则调用线程lock这个mutex对象（从此刻到直到其成员函数unlock被调用，当前线程拥有mutex对象）。
2、如果mutex目前被其他线程locked，则当前线程阻塞直到mutex被其他线程unlock。
3、如果mutex目前被当前线程lock，则会产生死锁错误。大部分情况会崩溃，因为mutex不支持递归。
*/

void *countgold() {
    int i; //local to each thread
    for (i = 0; i < 10000000; i++) {
        m.lock();
        sum += 1;
        m.unlock();
    }
    return NULL;
}

int main() {
    thread t1(countgold);
    thread t2(countgold);

    //Wait for both threads to finish
    t1.join();
    cout << "1\n";
    t2.join();
    cout << "2\n";

    cout << "sum = " << sum << endl;
    return 0;
}
