/*
 * @Author: your name
 * @Date: 2020-03-17 16:17:29
 * @LastEditTime: 2020-03-17 16:29:49
 * @LastEditors: liukai234
 * @Description: 对象数组实例
 * @FilePath: /test/EmpCube.cpp
 */
#include <iostream>

using namespace std;

class Box {
   public:
    Box(int h = 10, int w = 12, int len = 15)
        : height{h}, width{w}, length{len} {}
    int volume();

   private:
    int height;
    int width;
    int length;
};

int Box::volume() { return (height * width * length); }

int main() {
    Box a[3] = {Box(10, 12, 15), Box(15, 18, 20), Box(16, 20, 26)}; // 对象数组
    cout << a[0].volume() << endl;
    cout << a[1].volume() << endl;
    cout << a[2].volume() << endl;
    return 0;
}