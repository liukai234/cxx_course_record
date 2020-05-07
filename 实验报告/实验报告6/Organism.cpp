/*
 * @Description: 有机生物类，它封装了通用于蚂蚁和狮蚁的基本数据
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:29:43
 * @LastEditTime: 2020-05-07 17:10:11
 * @FilePath: /实验报告6/Organism.cpp
 */

#include <time.h>
#include <stdlib.h>

#include <iostream>

class Organism {
public:
    virtual void Move() = 0;
};


class Ant : public Organism {

};

class Doodlebug : public Organism {

};

void test_drive(){ std::cout << "test_drive()\n"; }

int main() { test_drive(); return 0; }