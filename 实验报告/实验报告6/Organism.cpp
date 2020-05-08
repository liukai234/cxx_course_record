/*
 * @Description: 有机生物类，它封装了通用于蚂蚁和狮蚁的基本数据
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:29:43
 * @LastEditTime: 2020-05-08 10:18:36
 * @FilePath: /实验报告6/Organism.cpp
 */

#include <time.h>
#include <stdlib.h>

#include <iostream>
constexpr int DIRECTION[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

unsigned int random_num_creater(const unsigned int &min_value, const unsigned int &max_value) {
    return rand() % (max_value - min_value) + min_value;
}

class Organism {
public:
    virtual void Move() = 0;
    virtual void Breed() = 0;
};

class Ant : public Organism {
public:
    Ant(unsigned int pos_x, unsigned int &pos_y) : pos_x_{pos_x}, pos_y_{pos_y}{}

    virtual void Move(){ std::cout << "Ant constructer\n"; }

    virtual void Breed() { 
        if(remain_breed == 0) {
            int dir_index = random_num_creater(0, 4);

        }
    }


private:
    int remain_breed = 3;
    unsigned int pos_x_;
    unsigned int pos_y_;
};

class Doodlebug : public Organism {
public:
    Doodlebug(unsigned int &pos_x, unsigned int &pos_y) : pos_x_{pos_x}, pos_y_{pos_y}{}

    virtual void Move(){ std::cout << "Ant constructer\n"; }

    virtual void Breed() { 
        if(remain_breed == 0) {
            int dir_index = random_num_creater(0, 4);

        } 
    }
    unsigned int pos_x() { return pos_x_; }
    unsigned int pos_y() { return pos_y_; }

private:
    int remain_life = 3;
    int remain_breed = 8;
    unsigned int pos_x_;
    unsigned int pos_y_;
};

void test_drive(){ 
    srand((unsigned)time(NULL));
    std::cout << "test_drive()\n";
    
    const unsigned int x_len = 20;
    const unsigned int y_len = 20;
    Organism* MAP[x_len][y_len];

    // fill MAP with 5 x And 100 o
    unsigned int init_doodlebug_nums_ = 5;
    for(unsigned int i = 0; i < init_doodlebug_nums_; i++) {
        unsigned int x_index_rand = random_num_creater(0, x_len);
        unsigned int y_index_rand = random_num_creater(0, y_len);
        // std::cout << x_index_rand << " " << y_index_rand << std::endl;
        Doodlebug doodlebug(x_index_rand, y_index_rand);
        if(MAP[x_index_rand][y_index_rand] == nullptr) { MAP[x_index_rand][y_index_rand] = &doodlebug; }
        else i--;
    }

    unsigned int init_ant_nums_ = 100;
    for(unsigned int i = 0; i < init_ant_nums_; i++) {
        unsigned int x_index_rand = random_num_creater(0, x_len);
        unsigned int y_index_rand = random_num_creater(0, y_len);

        Ant ant(x_index_rand, y_index_rand);
        if(MAP[x_index_rand][y_index_rand] == nullptr) { MAP[x_index_rand][y_index_rand] = &ant; }
        else i--;
    }
}

int main() { test_drive(); return 0; }