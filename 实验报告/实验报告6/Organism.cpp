/*
 * @Description: 有机生物类，它封装了通用于蚂蚁和狮蚁的基本数据
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:29:43
 * @LastEditTime: 2020-05-08 16:51:55
 * @FilePath: /实验报告6/Organism.cpp
 */

#include <time.h>
#include <stdlib.h>

#include <iostream>
#define ANT 1
#define DOODLEBUG 2
constexpr int DIRECTION[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

unsigned int random_num_creater(const unsigned int &min_value, const unsigned int &max_value) {
    return rand() % (max_value - min_value) + min_value;
}

class Organism {
public:
    virtual void Move() = 0;
    virtual void Breed() = 0;
    virtual void step_time() = 0;
    virtual int type() = 0;
};

const unsigned int x_len = 20;
const unsigned int y_len = 20;
Organism* MAP[x_len][y_len];

class Ant : public Organism {
public:
    Ant(unsigned int pos_x, unsigned int &pos_y) : pos_x_{pos_x}, pos_y_{pos_y}{}

    virtual void Move(){ 
        int temp = random_num_creater(0, 4);
        pos_x_ += DIRECTION[temp][0];
        pos_y_ += DIRECTION[temp][1];
        if(MAP[pos_x_][pos_y_] == nullptr && pos_x_ >= 0 && pos_x_ < x_len && pos_y_ >= 0 && pos_y_ < y_len) {
            MAP[pos_x_][pos_y_] = MAP[pos_x_ - DIRECTION[temp][0]][pos_y_ - DIRECTION[temp][1]]; 
        } else {
            pos_x_ -= DIRECTION[temp][0];
            pos_y_ -= DIRECTION[temp][1];
        }
    }

    virtual void Breed() {
        int dir_used[4];
        int dir_index = 0;
        bool stop = false;
        for(int i = 0; i < 4; i ++) { dir_used[i] = -1; }
        while(remain_breed == 0 && dir_index < 4) {
            int temp = random_num_creater(0, 4);

            for(int i = 0 ; i < 4; i++) { if(dir_used[i] == temp){ stop = true; } }
            if(stop) { break; }

            dir_used[dir_index] = temp;
            pos_x_ += DIRECTION[dir_used[dir_index]][0];
            pos_y_ += DIRECTION[dir_used[dir_index]][1];
            if(MAP[pos_x_][pos_y_] != nullptr && pos_x_ >= 0 && pos_x_ < x_len && pos_y_ >= 0 && pos_y_ < y_len) {
                Ant ant(pos_x_, pos_y_); 
                MAP[pos_x_][pos_y_] = &ant; 
                break;
            } else {
                pos_x_ -= DIRECTION[dir_used[dir_index]][0];
                pos_y_ -= DIRECTION[dir_used[dir_index]][1];
            }
            dir_index ++; 
        }
    }
    virtual int type() {
        return 1;
    }
    unsigned int pos_x(){
        return pos_x_;
    }

    unsigned int pos_y(){
        return pos_y_;
    }

    void step_time() {
        remain_breed --;
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
    void step_time() {
        remain_breed --;
    }
    virtual int type() {
        return 2;
    }
private:
    int remain_life = 3;
    int remain_breed = 8;
    unsigned int pos_x_;
    unsigned int pos_y_;
};

class Exec{
    

};

void test_drive(){ 
    srand((unsigned)time(NULL));
    std::cout << "test_drive()\n";
    
    unsigned int init_ant_nums_ = 100;
    for(unsigned int i = 0; i < init_ant_nums_; i++) {
        unsigned int x_index_rand = random_num_creater(0, x_len);
        unsigned int y_index_rand = random_num_creater(0, y_len);

        Ant ant(x_index_rand, y_index_rand);
        if(MAP[x_index_rand][y_index_rand] == nullptr) { MAP[x_index_rand][y_index_rand] = &ant; }
        else i--;
    }
    

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

    

    // 先假设20轮
    for(unsigned int i = 0; i < x_len; i++) {
        for(unsigned int j = 0; j < y_len; j++) {
            // doodlebug 先执行
            
            // ant
            MAP[i][j] == 1;
            if(MAP[i][j]->type() == ANT) {
                MAP[i][j]->Move();
                MAP[i][j]->Breed();
                MAP[i][j]->step_time();
            }
        }

    }
}

int main() { 
    std::cout << "1";
    test_drive(); 
    for(unsigned int i = 0; i < x_len; i++) {
        for(unsigned int j = 0; j < y_len; j++) {
            // doodlebug 先执行
            
            // ant
            if(MAP[i][j]->type() == ANT) {
                std::cout << "o ";
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0; 
}