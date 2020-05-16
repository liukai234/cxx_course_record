/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:18:34
 * @LastEditTime: 2020-05-16 17:27:48
 * @FilePath: /实验报告6/Ant.cpp
 */
#pragma once
#include "Organism.hpp"
#include <iostream>
#include <string.h>

// 先将所有的Ant进行移动然后繁殖
class Ant : public Organism {
public:
    Ant(int x_pos, int y_pos) : x_pos_{x_pos}, y_pos_{y_pos}{}

    int random_num_creater(int min_value, int max_value) {
        // 前闭后开
        return rand() % (max_value - min_value) + min_value;
    }

    // dosomething 替换为输出流重载
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

    virtual void move() {
        if(time_step_ != 0) { time_step_ --; }
        int index = random_num_creater(0, 4);
        // std::cout << "breed->creat random direction: " << "(" << DIRECTION[index][0]  << ", "<< DIRECTION[index][1] << ")" << "\n";
        int new_x_pos = x_pos_ + DIRECTION[index][0];
        int new_y_pos = y_pos_ + DIRECTION[index][1];
        if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
            std::cout << "Ant->move() success\n";
            
            Ant *ant = new Ant(new_x_pos, new_y_pos);
            ant->time_step_ = time_step_;
            ant->moved_ = true;
            Map[x_pos_][y_pos_] = nullptr;
            Map[new_x_pos][new_y_pos] = ant;
        }
        else {
            std::cout << "Ant->move() failed\n";
        }
    }

    virtual void breed() {
        if(time_step_ == 0) {
        //     time_step_ --;
        // } else {
            int ALL_DIR[4] = {-1, -1, -1, -1 };
            int arr_i = 0;
            while(true) {
                if(arr_i >= 4) {
                    break;
                    std::cout << "Ant->breed() failed: 所有方向都不能进行繁殖 \n";
                }
                int index = random_num_creater(0, 4);
                for(int i = 0; i < arr_i; i++) {
                    if (ALL_DIR[i] == index) { 
                        continue; 
                    }
                }
                ALL_DIR[arr_i++] = index;

                int new_x_pos = x_pos_ + DIRECTION[index][0];
                int new_y_pos = y_pos_ + DIRECTION[index][1];
                
                if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
                    // 繁殖成功的话才进行输出
                    Map[new_x_pos][new_y_pos] = new Ant(new_x_pos, new_y_pos);
                    time_step_ = 3;
                    std::cout << "Ant->breed() success\n";
                    print();
                    break;
                } else {
                    std::cout << "Ant->breed() success: 繁殖时发生越界或目标位置不为空\n";
                }
            }
        }
    }

    virtual int time_step() {
        return time_step_;
    }

    void get_pos() {
        std::cout << "breed->(" << x_pos_  << ", "<< y_pos_ << ")" << "\n";
    }

    virtual void set_moved(bool moved){
        moved_ = moved;
    }

    virtual bool ismoved(){
        return moved_;
    }

    virtual char type(){
        return 'o';
    }
private:
    int time_step_ = 3;
    int x_pos_;
    int y_pos_;
    bool moved_ = false;
};