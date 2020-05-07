/*
 * @Description: 有机生物类，它封装了通用于蚂蚁和狮蚁的基本数据
 * @LastEditors: liukai
 * @Date: 2020-05-07 08:29:43
 * @LastEditTime: 2020-05-07 17:05:20
 * @FilePath: /实验报告6/Organism.cpp
 */

#include <time.h>
#include <stdlib.h>

class Organism {
public:
    // 生物构造函数构造器包含两种生物的数量
    // Organism(const unsigned int &init_ant_nums, const unsigned int &init_doodlebug_nums)
    //      : init_ant_nums_{init_ant_nums}, init_doodlebug_nums_{init_doodlebug_nums}{}

    // 使用5只狮蚁和100只蚂蚁初始化这个网格世界。在每个time step后，都提示用户按Enter键移动到下一个time step
    // 动物会死亡
    // void map_creater(const size_t &x_len, const size_t &y_len){
    //     // create MAP with x_len And y_len
    //     MAP = new Organism* [x_len];
    //     for(size_t i = 0; i < x_len; ++ i) {
    //         MAP[i] = new Organism[y_len]();
    //     }
        
        // init ' '
        // for(size_t i = 0; i < x_len; i ++) {
        //     for(size_t j = 0; j < y_len; j ++) {
        //         MAP[i][j] = ' ';
        //     }
        // }

        // 使用5只狮蚁和100只蚂蚁初始化这个网格世界
        // fill MAP with 5 x And 100 o
        // for(unsigned int i = 0; i < init_doodlebug_nums_; i++) {
        //     unsigned int x_index_rand = random_num_creater(0, x_len);
        //     unsigned int y_index_rand = random_num_creater(0, y_len);

        //     // 判断该坐标下未填充
        //     if(MAP[x_index_rand][y_index_rand] == ' ') { MAP[x_index_rand][y_index_rand] = 'x'; }
        //     else i--;
        // }

        // for(unsigned int i = 0; i < init_ant_nums_; i++) {
        //     unsigned int x_index_rand = random_num_creater(0, x_len);
        //     unsigned int y_index_rand = random_num_creater(0, y_len);

        //     // 判断该坐标下未填充
        //     if(MAP[x_index_rand][y_index_rand] == ' ') { MAP[x_index_rand][y_index_rand] = 'o'; }
        //     else i--;
        // }
        // random_num_creater<int>(x_len, y_len);
    // }

    /**
     * @description: 随机构造器 
     * @param {const unsigned int} max_value min_value 
     * @param {template <typename T>} 目标数组 
     * @return: 在min_value到 max_value的随机数
     */
    // template <typename T>
    unsigned int random_num_creater(const unsigned int &max_value, const unsigned int &min_value) {

        // 如果不能随时间同步的话将随机时间种子提取到类的外部
        srand((unsigned)time(NULL));
        return rand() % (max_value - min_value) + min_value;
    }

    // 在ant And doodlebug中重载
    virtual void Move() = 0;
private:
    int max_value = 10;
    int min_value = 1;
    const unsigned int init_ant_nums_;
    const unsigned int init_doodlebug_nums_;
    Organism **MAP;
    static int TIME_STEP;
    static const int DIRECTION[4][2];
};

int Organism::TIME_STEP = 0;
const int Organism::DIRECTION[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// char Organism::TABLE[20][20] = {0};

class Ant : public Organism {
public:
    virtual void Move() {
        for(int i = 0; i < )
    }
};

class Doodlebug : public Organism {

};