/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-06 16:29:49
 * @LastEditTime: 2020-05-16 18:22:50
 * @FilePath: /实验报告6/Main.cpp
 */

#include "Organism.hpp"
#include "Organism.cpp"
#include "Ant.cpp"
#include "Doodlebug.cpp"

#include <stdlib.h>

void print();

int random_num_creater(int min_value, int max_value) {
    return rand() % (max_value - min_value) + min_value;
}

int main() {

    for(int x = 0; x < x_len; x ++) {
        for(int y = 0; y < y_len; y++){
            Map[x][y] = nullptr;
        }
    }

    srand((unsigned)time(NULL));
    
    for(int i = 0; i < 5; i++) {
        // dosomething 处理随机时重复的位置
        int x = random_num_creater(0, 20);
        int y = random_num_creater(0, 20);
        Map[x][y] = new Doodlebug(x, y);

    }
    
    for(int i = 0; i < 100; i++) {
        int x = random_num_creater(0, 20);
        int y = random_num_creater(0, 20);
        Map[x][y] = new Ant(x, y);
    }

    unsigned int count = 1;
    for(;count < 10; count ++){
        int ant_nums = 0;
        int doodlebug_nums = 0;
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o') ant_nums++;
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'x') doodlebug_nums++;
            }
        }
        if(ant_nums == x_len * y_len || doodlebug_nums == x_len * y_len) { break; }
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
        std::cout << "\nCurrent step time: " << count << std::endl; 
        print();
        std::cout << std::endl;
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o') {
                    Map[x][y]->breed();
                }
            }
        } 
    }
    
    return 0;
}


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