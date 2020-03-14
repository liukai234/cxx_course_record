/*
 * @Author: your name
 * @Date: 2020-03-05 23:38:43
 * @LastEditTime: 2020-03-06 11:40:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /chtml/test.cpp
 */
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>
int main() {
    std::ofstream outfile;
    unsigned int count = 1000;
    while (count > 0) {
        count--;
        outfile.open("1.html");
        std::stringstream sstr; // sstream
        sstr << count;
        outfile << "<meta http-equiv=\"refresh\" "
                   "content=\"1\"><html><body><h1>This is a C++ creat File " + sstr.str() + 
                   " flush </h1></body></html>";
        outfile.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // ∂‡œﬂ≥Ã
    }
    return 0;
}