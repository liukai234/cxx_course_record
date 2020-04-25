/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-24 09:49:59
 * @LastEditTime: 2020-04-25 11:51:03
 * @FilePath: /C++课程学习记录/lib/实验报告4/Staff.hpp
 */
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// class Company {
// public:
//     virtual ~Company() = default;
// };


class Staff {
public:
  Staff(){}
  Staff(const std::string &num, const std::string &name, int age, int wages) : num_{num}, name_{name}, age_{age}, wages_{wages} {}
  ~Staff(){
    // 对vector中指针指向的释放 dosomething
  }
  // ostream
  friend std::istream &operator>>(std::istream &in, Staff &obj) { return obj.inFromTerminal(in); }
  friend std::ostream &operator<<(std::ostream &out, Staff &obj) { return obj.outToTerminal(out); } 

  // fstream
  friend std::ifstream &operator>>(std::ifstream &inf, Staff &obj){ return obj.inFromFile(inf); }
  friend std::ofstream &operator<<(std::ofstream &of, Staff &obj) { return obj.outToFile(of); }
  
  void load(const std::string &filename, std::vector<Staff* > &vpStaff);
  void save(const std::string &filename, std::vector<Staff* > &vpStaff);
  
  const std::string num();

private:
  std::string num_;
  std::string name_;
  int age_;
  int wages_;
  std::istream &inFromTerminal(std::istream &in);
  std::ostream &outToTerminal(std::ostream &out);
  std::ifstream &inFromFile(std::ifstream &inf);
  std::ofstream &outToFile(std::ofstream &of);
};

class FILE_ERROR_Exception : public std::exception { 
public:
  virtual const char* what() const throw();
};
