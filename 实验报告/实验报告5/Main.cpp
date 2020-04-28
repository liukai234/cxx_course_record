/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-28 14:27:37
 * @LastEditTime: 2020-04-28 17:10:56
 * @FilePath: /C++课程学习记录/实验报告/实验报告5/Main.cpp
 */

#include <iostream>
#include <string>


class Goods{
public:
    Goods(const std::string &name, const int &weight) : name_{name}, weight_{weight}{}
    static int s_weight;
    static const int add(Goods &obj){ s_weight += obj.weight_; return s_weight; }
private:
    const std::string name_;
    const int weight_;
};

int Goods::s_weight = 0;

int main() {
    Goods good1("1", 1);
    std::cout << Goods::add(good1) << std::endl;
    return 0;
}