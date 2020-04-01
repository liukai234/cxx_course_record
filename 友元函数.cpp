/*
 * @Author: your name
 * @Date: 2020-02-25 17:08:53
 * @LastEditTime: 2020-04-01 11:02:27
 * @LastEditors: Please set LastEditors
 * @Description: 友元
 * @FilePath: /newclass/2.cpp
 */
#include <iostream>
class Box {
   private:
    double width;

   public:
    // 友元函数声明
    friend void print(Box &box);
    // 友元类声明
    friend class Mybox;
    void getWidth(double &wid) { width = wid; }
};

// 友元函数
void print(Box &box) { std::cout << box.width << std::endl; }

// 友元类的意义在哪里: 当Box中定义了Mybox友元时, 在Mybox类中可以轻松使用Box中的函数成员来完成本类数据的输出或其他操作
class Mybox {
   private:
    double width;

   public:
    Mybox(const int &num) { width = num; }
    void friendprint(Box &box) {
        box.getWidth(width);
        box.width = 5; // 使用友元类访问私有成员
    }
};

int main(int args, char *argv[]) {
    double wid;
    std::cin >> wid;
    Box box;
    Mybox mybox(3);
    mybox.friendprint(box);
    box.getWidth(wid);
    print(box);
}