/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-06 16:29:49
 * @LastEditTime: 2020-05-16 17:20:44
 * @FilePath: /实验报告6/Main.cpp
 */
/* 被捕食者是蚂蚁（ant），捕食者是狮蚁（doodlebug）。
这些小生物生活在20×20的网格世界中。每个单元格每次只能由一个个体占据。网格是封闭的，所以个体不允许
离开网格世界边缘。时间以time step为单位，个体在每个time step里面都要采取某项行动。具体规则如下：
1． 建立蚂蚁的行为规则模型。
（1）Move（移动）：在每个time step中，都随机向上、向下、向左或者向右移动。假如所选方向上的邻居单
元格被占据，或者会造成蚂蚁移动到网格的边缘之外，那么蚂蚁就停留在当前的单元格中。
（2）Breed（繁殖）：如果一只蚂蚁在3个time step中保存存活，在第3个time step结束之后（也就是在移
动之后），该蚂蚁会繁殖。为了模拟繁殖，需要在相邻（上、下、左或者右）的一个空单元格中创建一只新蚂蚁。
没有可用的空单元格，就不会繁殖。一旦成功繁殖出后代，除非再次经历3个time step，否则不能繁殖另一个后代。
2. 建立狮蚁的行为规则模型。
（1）Move（移动）：在每个time step中，假如有一只相邻的蚂蚁（上、下、左或者右），就移动到那个单元格，
吃掉蚂蚁。否则，狮蚁就按照和蚂蚁相同的规则移动。注意，狮蚁不能吃掉狮蚁。
（2）Breed（繁殖）：假如一只狮蚁在8个time step中保持存活，在第8个time step结束之后，会按照与蚂蚁
相同的方式繁殖出一只新狮蚁。
（3）Starve（饥饿）：假如一只狮蚁在连续3个time step中没有吃掉一只蚂蚁，在第3个time step结束之后，
它会感到饥饿并死亡。该狮蚁应从网格中拿掉。
（4）在一轮中，所有狮蚁都应该先于蚂蚁移动。
3. 编写主程序来模拟“捕食者-被捕食者”游戏。
（1）使用ASCII字符“o”表示蚂蚁，“x”表示狮蚁。创建名为Organism（有机生物）的类，它封装了通用于蚂蚁和
狮蚁的基本数据。该类应该有一个名为Move的virtual函数，它要在派生类Ant和Doodlebug中进行具体的定义。
可能需要额外的数据结构来跟踪已移动的生物。
（2）使用5只狮蚁和100只蚂蚁初始化这个网格世界。在每个time step后，都提示用户按Enter键移动到下一个
time step。应该看到狮蚁和蚂蚁数量的循环变化——虽然一些随机性的混乱可能造成一种或两种生物的毁灭。
 */

#include "Organism.hpp"
#include "Organism.cpp"
#include "Ant.cpp"
#include "Doodlebug.cpp"

#include <stdlib.h>

void print();

int main() {

    for(int x = 0; x < x_len; x ++) {
        for(int y = 0; y < y_len; y++){
            Map[x][y] = nullptr;
        }
    }

    srand((unsigned)time(NULL));
    
    Map[0][0] = new Ant(0, 0);
    Map[2][2] = new Doodlebug(2, 2);
    for(int count = 0; count < 15; count ++) {

        // doodlebug优先于ant移动
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                // 移动时将所有移动的Ant moved值 设为true
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'x' && !Map[x][y]->ismoved()) {
                    Map[x][y]->move();
                }
            }
        } 
        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                // 移动后将所有移动的Ant moved值 设回false
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
        std::cout << "move->\n"; print();

        for(int x = 0; x < x_len; x ++) {
            for(int y = 0; y < y_len; y++){
                if(Map[x][y] != nullptr && Map[x][y]->type() == 'o') {
                    Map[x][y]->breed();
                }
            }
        } 
        // std::cout << "breed->\n";
        // print();
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
            if(x != x_len - 1) {
                printf("-----------\n");
            }
        }
    }