/*
 * @Author: your name
 * @Date: 2020-02-28 14:07:20
 * @LastEditTime: 2020-03-04 00:23:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /exam/test.cpp
 */
#include <iostream>
using std::cin;
using std::cout;

int fac(int n) {
    if (n == 1) return 1;
    return n * fac(n - 1);
}

int queue[1000][5];

int main() {
    int n = 5;
    int origin_arr[n] = {1, 2, 3, 4, 5};

    // 输出单个元素的集合
    for (int i = 0; i < n; i++) {
        cout << origin_arr[i] << " ";
    }

    // 初始化变量和数组: queue数组的功能相当于队列, 能够保存前一次的排列结果
    int front = -1;  // 查看队首
    int push = 0;    // 加入队列
    for (int i = 0; i < n; i++) {
        queue[0][i] = origin_arr[i];  // 初始化队首
    }

    for (int i = 2; i <= n; ++i) {
        // origin_arr[i - 1]
        for (int j = 1; j <= fac(i - 1); j++) {
            front++;
            for (int k = i; k >= 1; k--) {
                push++;
                int iter = 0; // 遍历器

                // per表示当前插入元素的前缀, suf表示后缀
                for (int pre = 0; pre < k - 1; pre++) {
                    queue[push][iter++] = queue[front][pre];
                    cout << queue[front][pre];
                }

                // 加入当前元素
                queue[push][iter++] = origin_arr[i - 1];
                cout << origin_arr[i - 1];
                
                for (int suf = k - 1; suf < i - 1; suf++) {
                    queue[push][iter++] = queue[front][suf];
                    cout << queue[front][suf];
                }
                cout << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}