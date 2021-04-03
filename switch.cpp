#include <iostream>
using namespace std;


int main(int argc, char *argv[]){
    int a = 1;
    switch (a) {
        case 0:
            /*
             * switch 只能跳过变量初始化，不能跳过变量定义
             */
            int b;
            b = 0;
            cout << b;
            break;
        case 1:
            b = 2;
            cout << b;
            break;
    }
}