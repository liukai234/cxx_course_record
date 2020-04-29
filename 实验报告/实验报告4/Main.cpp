/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-28 14:27:37
 * @LastEditTime: 2020-04-29 10:28:41
 * @FilePath: /C++课程学习记录/实验报告/实验报告4/Main.cpp
 */

// #include "include/dbg.h"
#include <iostream>
// #include <chrono>
// using namespace std::chrono;

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
    int days_of_month_[12];
    void days_of_month(int year);
    bool is_leap_year(int year);
};

bool CDate::is_leap_year(int year){
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void CDate::days_of_month(int year){
    auto copy_month = [&](int *src, int *dis){
        for(int i = 0; i < 12; i++, src++, dis++) { *dis = *src; }
    };
    if(is_leap_year(year)){
        int temp[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        copy_month(temp, days_of_month_);
    } else {
        int temp[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        copy_month(temp, days_of_month_);
    }
}

void CDate::SetDate(int year = 1970, int month = 1, int day = 1) {
    // 若日期不在范围抛出异常
    year_ = year;
    month_ = month;
    day_ = day;
}

void CDate::AddOneDay(){
    days_of_month(year_);
    ++day_; std::cout << "add one day: ";
    if(day_ > days_of_month_[month_ - 1]) { day_ = 1; ++month_; }
    if(month_ > 12) { month_ = 1; ++ year_; days_of_month(year_); }
}

void CDate::print() {
    std::cout << year_ << "/" << month_ << "/" << day_ << std::endl;
}

int main() {
    CDate date(2000);
    date.print();

    date.SetDate(2000, 2, 28);
    date.print();
    date.AddOneDay();
    date.print();

    date.SetDate(2000, 2, 29);
    date.print();
    date.AddOneDay();
    date.print();

    date.SetDate(2000, 12, 31);
    date.print();
    date.AddOneDay();
    date.print();

    return 0;
}