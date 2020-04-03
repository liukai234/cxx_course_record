/*
 * @Author: your name
 * @Date: 2020-04-03 09:51:02
 * @LastEditTime: 2020-04-03 09:51:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/assert断言/ignore_assert.c
 */


# define NDEBUG

#include<assert.h>

int main(){
    int x=7;
    assert(x==5);
    return 0;
}
