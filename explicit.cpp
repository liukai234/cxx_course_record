/*
 * @Author: liukai
 * @Date: 2020-02-22 13:37:31
 * @LastEditTime: 2020-02-23 10:17:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wanmen2/mytest.cpp
 */
#include <iostream>
using namespace std;

class Add{
private:
    int num1;
    int num2;
public:
    explicit Add(const int& a,const int& b) : num1(a), num2(b){ // explicit ÏÔÐÔµÄ
    }
    int returnAdd() {
        return num1 + num2;
    }
    ~Add(){
        cout << "~Add" << endl;
    }
};

/**
 * @description: 
 * @param {type} 
 * @return: 
 */
int main(int args, char *argv[]) {
    int Inta = 1;
    int Intb = 2;

    Add add(Inta, Intb);
    cout << add.returnAdd() << endl;
    return 0;
} 
