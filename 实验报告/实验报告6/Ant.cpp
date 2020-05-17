/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:18:34
 * @LastEditTime: 2020-05-17 03:02:14
 * @FilePath: /实验报告6/Ant.cpp
 */
#pragma once
#include "Organism.hpp"
#include <iostream>
#include <string.h>

// 先将所有的Ant进行移动然后繁殖
class Ant : public Organism {
public:
    Ant(const int &x_pos, const int &y_pos) : x_pos_{x_pos}, y_pos_{y_pos}{}

    virtual void move() {
        if(time_step_ != 0) { time_step_ --; }
        int index = random_num_creater(0, 4);
        int new_x_pos = x_pos_ + DIRECTION[index][0];
        int new_y_pos = y_pos_ + DIRECTION[index][1];
        if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
#ifdef DEBUG
            std::cout << "Ant->move() success\n";
#endif
            // dosomething 使用move拷贝函数
            Ant *ant = new Ant(new_x_pos, new_y_pos);
            ant->time_step_ = time_step_;
            ant->moved_ = true;
            Map[x_pos_][y_pos_] = nullptr;
            Map[new_x_pos][new_y_pos] = ant;
        }
        else {
#ifdef DEBUG
            std::cout << "Ant->move() failed\n";
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
                    std::cout << "Ant->breed() failed: 所有方向都不能进行繁殖 \n";
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
                
                if(new_x_pos >= 0 && new_x_pos < x_len && new_y_pos >= 0 && new_y_pos < y_len && Map[new_x_pos][new_y_pos] == nullptr){
                    // 繁殖成功的话才进行输出
                    Map[new_x_pos][new_y_pos] = new Ant(new_x_pos, new_y_pos);
                    time_step_ = 3; // 更新time_step_
#ifdef DEBUG
                    std::cout << "Ant->breed() success\n";
                    print();
#endif
                    add_one();
                    break;
                } else {
#ifdef DEBUG
                    std::cout << "Ant->breed() success: 繁殖时发生越界或目标位置不为空\n";
#endif
                }
            }
        }
    }

    virtual int time_step() { return time_step_; }
    void get_pos() { std::cout << "breed->(" << x_pos_  << ", "<< y_pos_ << ")" << "\n"; }
    virtual void set_moved(bool moved){ moved_ = moved; }
    virtual bool ismoved(){ return moved_; }
    virtual char type(){ return 'o'; }
    const static int get_sum() { return ant_sum_; }
    virtual void kill_one() { ant_sum_ --; }
    virtual void add_one() { ant_sum_ ++; }

private:
    // time_step_ 为 0 时表示生物将要 breed
    int time_step_ = 3;
    int x_pos_;
    int y_pos_;
    bool moved_ = false;
    static int ant_sum_;
};

int Ant::ant_sum_ = 0;