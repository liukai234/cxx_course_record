//
// Created by lk234 on 2020/10/31 031.
//

#include <stdio.h>

/*
 * 内存地址输出
 * 应根据大小端机器模式读
 */
typedef unsigned char * byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for(i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}