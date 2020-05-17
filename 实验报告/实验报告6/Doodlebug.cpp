/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:18:46
 * @LastEditTime: 2020-05-17 11:12:21
 * @FilePath: /实验报告6/Doodlebug.cpp
 */

#pragma once
#include "Organism.hpp"
#include <iostream>
#include <string.h>

class Doodlebug : public Organism {
public:
    Doodlebug(const int &x_pos, const int &y_pos) : x_pos_{x_pos}, y_pos_{y_pos}{}

    virtual void move() {
        if(time_step_ != 0) { time_step_ --; }
        if(starve_ < 0) { return; }
        int ALL_DIR[4] = {-1, -1, -1, -1 };
        int arr_i = 0;
        while(true) {
            if(arr_i >= 4) {
                break;
                std::cout << "Doodlebug->move() failed: eat时 周围无ant\n";
            }
            int index = random_num_creater(0, 4);
            bool jump_this = false;
            for(int i = 0; i < arr_i; i++) {
                if (ALL_DIR[i] == index) { 
                    jump_this = true;
                }
            }

            if(jump_this) { continue; }

            ALL_DIR[arr_i++] = index;

            int new_x_pos = x_pos_ + DIRECTION[index][0];
            int new_y_pos = y_pos_ + DIRECTION[index][1];
            
            if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] != nullptr && Map[new_x_pos][new_y_pos]->type() == 'o'){
                std::cout << "Doodlebug->move() eat success\n";
                Map[new_x_pos][new_y_pos]->kill_one();
                Doodlebug *doodlebug = new Doodlebug(new_x_pos, new_y_pos);
                doodlebug->time_step_ = time_step_;
                // doodlebug->starve_ = 3; // 更新为3
                doodlebug->moved_ = true;
                Map[x_pos_][y_pos_] = nullptr;
                Map[new_x_pos][new_y_pos] = doodlebug;
                return;
            } else {
#ifdef DEBUG
                std::cout << "Doodlebug->move(): eat时 越界或目标位置不可用\n";
#endif
            }
        }

        // 在time_step之后
        if(starve_ == 0) { kill_one(); Map[x_pos_][y_pos_] = nullptr; return; }
        int index = random_num_creater(0, 4);
        int new_x_pos = x_pos_ + DIRECTION[index][0];
        int new_y_pos = y_pos_ + DIRECTION[index][1];

        if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
#ifdef DEBUG
            std::cout << "Doodlebug->move() success\n";
#endif
            // 就算本回合没有移动成功，也要消耗饥饿值
            starve_ --;
            // printf("%d\n", starve_);
            Doodlebug *doodlebug = new Doodlebug(new_x_pos, new_y_pos);
            doodlebug->time_step_ = time_step_;
            doodlebug->starve_ = starve_;
            doodlebug->moved_ = true;
            Map[x_pos_][y_pos_] = nullptr;
            Map[new_x_pos][new_y_pos] = doodlebug;
            
            // 移动成功的话才进行输出
            // print();
        
        }
        else {
            // 就算本回合没有移动成功，也要消耗饥饿值
            starve_ --;
            // printf("%d\n", starve_);
#ifdef DEBUG
            std::cout << "Doodlebug->move() failed\n";
#endif
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
#ifdef DEBUG
                    std::cout << "Doodlebug->breed()\n";
                    print();
#endif
                    add_one();
                    break;
                } else {
#ifdef DEBUG
                    std::cout << "Doodlebug->breed(): 繁殖时发生越界或目标位置不为空\n";
#endif
                }
            }
        }
    }

    virtual int time_step() { return time_step_; }
    void get_pos() { std::cout << "breed->(" << x_pos_  << ", "<< y_pos_ << ")" << "\n"; }
    virtual void set_moved(bool moved){ moved_ = moved; }
    virtual bool ismoved(){ return moved_; }
    virtual char type(){ return 'x'; }
    const static int get_sum() { return doodlebug_sum_; }
    virtual void kill_one() { doodlebug_sum_ --; }
    virtual void add_one() { doodlebug_sum_ ++; }
    
    // Doodlebug &operator=(Doodlebug&& current_obj){}
    // dynamic_cast< * >

private:
    int time_step_ = 8;
    int x_pos_;
    int y_pos_;
    int starve_ = 3;
    bool moved_ = false;
    static int doodlebug_sum_;
};

int Doodlebug::doodlebug_sum_ = 0;

