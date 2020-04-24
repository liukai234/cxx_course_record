/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-24 10:03:17
 * @LastEditTime: 2020-04-24 18:19:38
 * @FilePath: /C++课程学习记录/lib/实验报告4/Staff.cpp
 */

#include "Staff.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>

// class FILE_ERROR_Exception : public std::exception { 
// public:
const char* FILE_ERROR_Exception::what() const throw(){
  return "文件读取错误";
}

std::istream &Staff::inFromTerminal(std::istream &in) {
  in >> num_ >> name_ >> age_ >> wages_;
	return in;
}

std::ostream &Staff::outToTerminal(std::ostream &out) {
  out << "号码: " << num_ << " " 
      << "姓名: " << name_ << " " 
      << "年龄: " << age_ << " " 
      << "工资: " << wages_ << "\n";
	return out;
}

std::ifstream &Staff::inFromFile(std::ifstream &inf) {
	inf >> num_ >> name_ >> age_ >> wages_;
	return inf;
}

std::ofstream &Staff::outToFile(std::ofstream &of) {
  // 设定输出格式
	of << num_ << " " << name_ << " " << age_ << " " << wages_ << " ";
	return of;
}

void load(const std::string &filename, std::vector<Staff* > &vpStaff) {
  Staff temp_staff; // 没有参数的构造函数
  try{
      std::ifstream infile("Staffinfo.txt", std::ios::in);
      while(infile.peek() != EOF) { 
        // std::cout << infile.peek() << std::endl;  
        infile >> temp_staff;
        vpStaff.push_back(&temp_staff);
      }
    infile.close();
    // std::cout << "异常检测: " << std::endl;
  }catch(FILE_ERROR_Exception e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "this............\n";
  // return vpStaff;
  // if(!infile) {std::cerr << "Staffinfo cannot open" << std::endl; exit(1); }
}