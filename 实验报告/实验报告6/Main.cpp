/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-06 16:29:49
 * @LastEditTime: 2020-05-17 11:32:50
 * @FilePath: /实验报告6/Main.cpp
 */

#include "Organism.hpp"
#include "Organism.cpp"
#include "Ant.cpp"
#include "Doodlebug.cpp"

#include <stdlib.h>

int main() {

    // 初始化
    srand((unsigned)time(NULL));

    for(int x = 0; x < x_len; x ++) {
        for(int y = 0; y < y_len; y++){
            Map[x][y] = nullptr;
        }
    }

    // 5 doodlebugs
    for(int i = 0; i < init_doodlebugs; i++) {
        int x = random_num_creater(0, x_len);
        int y = random_num_creater(0, y_len);
        if(Map[x][y] == nullptr) { Map[x][y] = new Doodlebug(x, y); Map[x][y]->add_one(); }
        else { i --; }
    }
    
    // 100 ants
    for(int i = 0; i < init_ants; i++) {
        int x = random_num_creater(0, x_len);
        int y = random_num_creater(0, y_len);
        if(Map[x][y] == nullptr) { Map[x][y] = new Ant(x, y); Map[x][y]->add_one(); }
        else { i --; }
    }

    unsigned int count = 1;
    for(;count < 20; count ++){
        // int ant_nums = 0;
        // int doodlebug_nums = 0;

        // doodlebug优先于ant移动
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'x' && !Map[x][y]->ismoved()) {
                    Map[x][y]->move();
                }
            }
        } 
        
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'x' && Map[x][y]->ismoved()) {
                    Map[x][y]->set_moved(false);
                }
            }
        } 

        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'x') {
                    Map[x][y]->breed();
                }
            }
        } 

        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                // 移动时将所有移动的Ant moved值 设为true
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o' && !Map[x][y]->ismoved()) {
                    Map[x][y]->move();
                }
            }
        }
        
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                // 移动后将所有移动的Ant moved值 设回false
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o' &&  Map[x][y]->ismoved()) {
                    Map[x][y]->set_moved(false);
                }
            }
        } 
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o') {
                    Map[x][y]->breed();
                }
            }
        } 
        
        std::cout << "\nCurrent step time: " << count << std::endl; 
        print();
        std::cout << std::endl;
        // std::cout << "Doodlesum_sum: "<< Doodlebug::get_sum() << "\n";
        // std::cout << "Ant_sum: "<< Ant::get_sum() <<"\n";

        if(Doodlebug::get_sum() == 0 &&  Ant::get_sum() == 0) {
            std::cout << "两种种群全部灭亡\n";
            break;
        }

        if(Ant::get_sum() == x_len * y_len) {
            std::cout << "Doodlebug种群全部灭亡\n";
            break;
        }
    }
    
    return 0;
}
