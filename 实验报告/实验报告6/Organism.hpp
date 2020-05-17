/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-16 09:44:49
 * @LastEditTime: 2020-05-17 11:09:22
 * @FilePath: /实验报告6/Organism.hpp
 */ 
#pragma once

class Organism {
public:
    virtual void move() = 0;
    virtual void breed() = 0;
    virtual bool ismoved() = 0;
    virtual void set_moved(bool) = 0;
    virtual int time_step() = 0;
    virtual char type() = 0;
    virtual void kill_one() = 0;
    virtual void add_one() = 0;

    
    // virtual void x_pos() = 0;
    // virtual void y_pos() = 0;
    // virtual void set_x_pos(int) = 0;
    // virtual void set_y_pos(int) = 0;
};

constexpr int DIRECTION[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};