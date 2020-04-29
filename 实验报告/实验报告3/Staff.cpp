/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-24 10:03:17
 * @LastEditTime: 2020-04-29 09:08:25
 * @FilePath: /C++课程学习记录/实验报告/实验报告3/Staff.cpp
 */

#include "Staff.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#ifdef DEBUG
#include "include/dbg.h"
#endif

const char* FILE_ERROR_Exception::what() const throw(){
  return "Exception: FILE_OPEN_ERROR";
}

const std::string Staff::num(){
  return num_;
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
	of << num_ << " " << name_ << " " << age_ << " " << wages_;
	return of;
}

void Staff::load(const std::string &filename, std::vector<Staff* > &vpStaff) {
  std::cout << "load: " << filename << std::endl;
  try{
      // [来自]C++核心准则 2019年12月8日
      // std::ifstream input{filename}; // 即使发生错误文件仍可关闭
      std::ifstream infile(filename, std::ios::in);
      if(!infile) {throw FILE_ERROR_Exception();} // 如果在这里发生错误，文件无法关闭
      while(infile.peek() != EOF) { 
        vpStaff.push_back(new Staff);
        infile >> *vpStaff.back();
#ifdef DEBUG
        dbg(vpStaff.back());
        dbg(vpStaff.size());
        std::cout << *vpStaff.back();
#endif
      }
      infile.close();
  }catch(FILE_ERROR_Exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void Staff::save(const std::string &filename, std::vector<Staff* > &vpStaff) {
  std::cout << "save: " << filename << std::endl;
  try{
      std::ofstream outfile(filename, std::ios::out);
      if(!outfile) {throw FILE_ERROR_Exception();}

      // output to file And format
      for(std::vector<Staff* >::iterator ite = vpStaff.begin(); ite != vpStaff.end(); ite++){
        outfile << **ite;
        if(ite + 1 != vpStaff.end()) outfile << "\n";
      } 
#ifdef DEBUG
        dbg(vpStaff.size());
        std::cout << *vpStaff.back();
#endif
    outfile.close();
  }catch(FILE_ERROR_Exception &e) {
    std::cout << e.what() << std::endl;
  }
}