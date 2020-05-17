/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-16 09:53:41
 * @LastEditTime: 2020-05-17 11:06:28
 * @FilePath: /实验报告6/Organism.cpp
 */ 
#pragma once
#include "Organism.hpp"
#include <stdlib.h>
#include <stdio.h>

constexpr int x_len = 3;
constexpr int y_len = 3;

Organism *Map[x_len][y_len];

const int random_num_creater(const int &min_value, const int &max_value) {
    return rand() % (max_value - min_value) + min_value;
}

void print() {
    for(int x = 0; x < x_len; x ++) {
        for(int y = 0; y < y_len; y++){
            if(Map[x][y] == nullptr) {
                printf("   ");
            } else {
                printf(" %c ", Map[x][y]->type());
            }
            if(y != y_len - 1){
                printf("|");
            }
        }
        printf("\n");
        // if(x != x_len - 1) {
        //     printf("-----------\n");
        // }
    }
}