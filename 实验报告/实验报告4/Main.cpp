/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-28 14:27:37
 * @LastEditTime: 2020-04-28 16:36:13
 * @FilePath: /C++课程学习记录/实验报告/实验报告4/Main.cpp
 */

#include "include/dbg.h"

#include <iostream>



class CDate{
public:
    CDate(int year = 1970, int month = 1, int day = 1) : year_{year}, month_{month}, day_{day}{}
    ~CDate(){}
    void SetDate(int, int, int);
    void AddOneDay();
    void print();
private:
    int year_;
    int month_;
    int day_;
};

void CDate::SetDate(int year = 1970, int month = 1, int day = 1) {
    year_ = year;
    month_ = month;
    day_ = day;
}

void CDate::AddOneDay(){
    ++day_;
}

void CDate::print() {
    std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
}

int main() {
    CDate date(2000);
    // date.SetDate(2000);
    date.AddOneDay();
    date.print();
    return 0;
}