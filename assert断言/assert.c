/*
 * @Author: your name
 * @Date: 2020-04-03 09:50:24
 * @LastEditTime: 2020-04-03 09:56:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/assert断言/assert.c
 */
#include <assert.h>
#include <stdio.h>

int main() {
    int x = 7;
    x = 9;
    // Programmer assumes x to be 7 in rest of the code
    assert(x == 7);
    // 断言 x == 7, 若不是则中止程序
    printf("assert end\n");
    /* Rest of the code */

    return 0;
}
