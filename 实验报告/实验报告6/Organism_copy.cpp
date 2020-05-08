/*
 * @Description: 有机生物类，它封装了通用于蚂蚁和狮蚁的基本数据
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:29:43
 * @LastEditTime: 2020-05-08 09:39:38
 * @FilePath: /实验报告6/Organism_copy.cpp
 */

#include <time.h>
#include <stdlib.h>

#include <iostream>

class Organism {
public:
    // Organism(const size_t &x_len, const size_t &y_len) : x_len_{x_len}, y_len_{y_len}{}

    void map_creater(const size_t &x_len, const size_t &y_len){
        // create MAP with x_len And y_len
        MAP = new Organism** [x_len];
        for(size_t i = 0; i < x_len; ++ i) {
            MAP[i] = new Organism*[y_len];
        }
        
        // init nullptr
        for(size_t i = 0; i < x_len; i ++) {
            for(size_t j = 0; j < y_len; j ++) {
                MAP[i][j] = nullptr;
            }
        }
    }

    unsigned int random_num_creater(const unsigned int &max_value, const unsigned int &min_value) {
        // 如果不能随时间同步的话将随机时间种子提取到类的外部
        srand((unsigned)time(NULL));
        return rand() % (max_value - min_value) + min_value;
    }

    // 在ant And doodlebug中重载
    virtual void Move() = 0;

protected:
    const size_t x_len_;
    const size_t y_len_;
    Organism ***MAP;
    
private:
    static int TIME_STEP;
    static const int DIRECTION[4][2];
};

int Organism::TIME_STEP = 0;
const int Organism::DIRECTION[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// char Organism::TABLE[20][20] = {0};

// class Ant : public Organism {
// public:
//     // Ant(const unsigned int &init_ant_nums) : init_ant_nums_{init_ant_nums}{}
//     virtual void Move(){ std::cout << "Ant constructer\n"; }
//     // 使用5只狮蚁和100只蚂蚁初始化这个网格世界
//     void init_ant(){
//         // fill MAP with 5 x And 100 o
//         for(unsigned int i = 0; i < init_ant_nums_; i++) {
//             unsigned int x_index_rand = random_num_creater(0, x_len_);
//             unsigned int y_index_rand = random_num_creater(0, y_len_);

//             // 判断该坐标下未填充
//             if(MAP[x_index_rand][y_index_rand] == nullptr) { MAP[x_index_rand][y_index_rand] = ant_; }
//             else i--;
//         }
//     }
// private:
//     const unsigned int init_ant_nums_;
//     Ant ant_;
// };

// class Doodlebug : public Organism {
//     virtual void Move(){ std::cout << "Ant constructer\n"; }

// };

void test_driver(){
    Organism *organism_map;
    organism_map->map_creater(20, 20);
    
}
int main() { test_driver(); return 0; }