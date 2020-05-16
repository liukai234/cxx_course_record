/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:18:46
 * @LastEditTime: 2020-05-16 18:23:11
 * @FilePath: /实验报告6/Doodlebug.cpp
 */


#pragma once
#include "Organism.hpp"
#include <iostream>
#include <string.h>

// 先将所有的Doodlebug进行移动然后繁殖
class Doodlebug : public Organism {
public:
    Doodlebug(int x_pos, int y_pos) : x_pos_{x_pos}, y_pos_{y_pos}{}

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
        if(starve_ != 0) { starve_ --; }
        if(starve_ == 0) { Map[x_pos_][y_pos_] == nullptr; return; }
        int ALL_DIR[4] = {-1, -1, -1, -1 };
        int arr_i = 0;
        while(true) {
            if(arr_i >= 4) {
                break;
                std::cout << "Doodlebug->move() failed: eat时 周围无ant\n";
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
            
            if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] != nullptr && Map[new_x_pos][new_y_pos]->type() == 'o'){
                std::cout << "Doodlebug->move() eat success\n";
                Doodlebug *doodlebug = new Doodlebug(new_x_pos, new_y_pos);
                doodlebug->time_step_ = time_step_;
                doodlebug->starve_ = starve_;
                doodlebug->moved_ = true;
                Map[x_pos_][y_pos_] = nullptr;
                Map[new_x_pos][new_y_pos] = doodlebug;
                break;
            } else {
                std::cout << "Doodlebug->move(): eat时 越界或目标位置不可用\n";
            }
        }

        int index = random_num_creater(0, 4);
        int new_x_pos = x_pos_ + DIRECTION[index][0];
        int new_y_pos = y_pos_ + DIRECTION[index][1];

        if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
            std::cout << "Doodlebug->move() success\n";
            
            Doodlebug *doodlebug = new Doodlebug(new_x_pos, new_y_pos);
            doodlebug->time_step_ = time_step_;
            doodlebug->moved_ = true;
            Map[x_pos_][y_pos_] = nullptr;
            Map[new_x_pos][new_y_pos] = doodlebug;
            
            // 移动成功的话才进行输出
            // print();
        
        }
        else {
            std::cout << "Doodlebug->move() failed\n";
        }
    }

    virtual void breed() {
        if(time_step_ == 0) {
            int ALL_DIR[4] = {-1, -1, -1, -1 };
            int arr_i = 0;
            while(true) {
                if(arr_i >= 4) {
                    break;
                    std::cout << "Doodlebug->breed() failed: 所有方向都不能进行繁殖\n";
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
                    Map[new_x_pos][new_y_pos] = new Doodlebug(new_x_pos, new_y_pos);
                    time_step_ = 3;
                    std::cout << "Doodlebug->breed()\n";
                    print();
                    break;
                } else {
                    std::cout << "Doodlebug->breed(): 繁殖时发生越界或目标位置不为空\n";
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
        return 'x';
    }
private:
    int time_step_ = 8;
    int x_pos_;
    int y_pos_;
    int starve_ = 3;
    bool moved_ = false;
};

