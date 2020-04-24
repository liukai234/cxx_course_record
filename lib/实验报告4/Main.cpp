/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-24 09:42:15
 * @LastEditTime: 2020-04-24 15:16:01
 * @FilePath: /C++课程学习记录/lib/实验报告4/Main.cpp
 */

/*
(1) 按职工号由小到大的顺序将5个员工的数据(包括号码、姓名、年龄、工资)输出到磁盘文件中保存。
(2) 从键盘输入两个员工的数据(职工号大于已有的职工号)，增加到文件的末尾。
(3) 输出文件中全部职工的数据。
(4) 从键盘输入一个号码，从文件中查找有无此职工号，如有则显示此职工是第几个职工，以及此职工的
    全部数据。如没有，就输出“无此人”。可以反复多次查询，如果输入查找的职工号为0，就结束查询。
*/

#include "Staff.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
int main() {
  std::string filename = "Staffinfo.txt";
  std::vector<Staff* > vpStaff;
  load(filename, vpStaff);
  // (1) 按职工号由小到大的顺序将5个员工的数据(包括号码、姓名、年龄、工资)输出到磁盘文件中保存
  // std::vector<Staff* > vpStaff;
  Staff staff1("10001", "质检1", 1, 1);
  vpStaff.push_back(&staff1);
  Staff staff2("10002", "质检2", 1, 1);
  vpStaff.push_back(&staff2);
  Staff staff3("10003", "质检3", 1, 1);
  vpStaff.push_back(&staff3);
  Staff staff4("10004", "质检4", 1, 1);
  vpStaff.push_back(&staff4);
  Staff staff5("10005", "质检5", 1, 1);
  vpStaff.push_back(&staff5);

  std::ofstream outfile("Staffinfo.txt", std::ios::out);
  if(!outfile) {std::cerr << "Staffinfo cannot open" << std::endl; exit(1); }
  for (auto &x : vpStaff) { outfile << (*x); }
  outfile.close();

  // (2) 从键盘输入两个员工的数据(职工号大于已有的职工号)，增加到文件的末尾。
  Staff temp_staff; // 没有参数的构造函数
  std::ifstream infile("Staffinfo.txt", std::ios::in);
  if(!infile) {std::cerr << "Staffinfo cannot open" << std::endl; exit(1); }
  
  while(infile.peek() != EOF) { 
    // std::cout << infile.peek() << std::endl;
    infile >> temp_staff;
  }
  infile.close();
  // std::string num;
  // std::string name;
  // int age;
  // int wages;
  std::cout << "endl" << std::endl;
  
  // (3) 输出文件中全部职工的数据。
  infile.open("Staffinfo.txt", std::ios::in);
  if(!infile) {std::cerr << "Staffinfo cannot open" << std::endl; exit(1); }
  while(infile.peek() != EOF) { 
    infile >> temp_staff;
    std::cout << temp_staff;
  }
  infile.close();
  return EXIT_SUCCESS; 
}