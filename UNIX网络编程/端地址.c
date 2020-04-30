/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 09:35:24
 * @LastEditTime: 2020-04-30 09:38:18
 * @FilePath: /UNIX网络编程/端地址.c
 */

# include <stdio.h>

int main() {
    unsigned int uint = 0x12345678;
    unsigned char *p = (unsigned char *)&uint;
    printf("%0x %0x %0x %0x", p[0], p[1], p[2], p[3]);
    return 0;
}