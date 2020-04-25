/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-24 09:42:15
 * @LastEditTime: 2020-04-25 12:27:27
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
#include <algorithm>

int main() {
  const std::string filename = "Staffinfo.txt";
  Staff staff_file;
/*   staff_file.load(filename, vpStaff);
  for(auto &x : vpStaff) { std::cout << *x; }
  staff_file.save(filename, vpStaff); */
  
  // (1) 按职工号由小到大的顺序将5个员工的数据(包括号码、姓名、年龄、工资)输出到磁盘文件中保存
  std::vector<Staff* > inputStaff;
  Staff* staff1 = new Staff("10001", "质检1", 1, 1);
  inputStaff.push_back(staff1);
  Staff* staff2 = new Staff("10002", "质检2", 2, 2);
  inputStaff.push_back(staff2);
  Staff* staff3 = new Staff("10003", "质检3", 3, 3);
  inputStaff.push_back(staff3);
  Staff* staff4 = new Staff("10004", "质检4", 4, 4);
  inputStaff.push_back(staff4);
  Staff* staff5 = new Staff("10005", "质检5", 5, 5);
  inputStaff.push_back(staff5);
#ifdef DEBUG
  for(auto &x : inputStaff) { std::cout << *x; }
#endif
  staff_file.save(filename, inputStaff);
  
  // (2) 从键盘输入两个员工的数据(职工号大于已有的职工号)，增加到文件的末尾。
  try{
    std::ofstream outfile(filename, std::ios::out | std::ios::app);
    if(!outfile) {throw FILE_ERROR_Exception();}
    Staff temp_staff; 
    std::cout << "input 号码 姓名 年龄 工资 \n";
    for(int i = 0; i < 2; i++) {
      std::cin >> temp_staff;
      outfile << "\n";
      outfile << temp_staff;
    }
    outfile.close();
  }catch(FILE_ERROR_Exception &e) {
    std::cout << e.what() << std::endl;
  }

  // (3) 输出文件中全部职工的数据。
  std::vector<Staff* > outputStaff;
  staff_file.load(filename, outputStaff);
  for(auto &x : outputStaff) { std::cout << *x; }
  // staff_file.save(filename, outputStaff);

  // (4) 从键盘输入一个号码，从文件中查找有无此职工号，如有则显示此职工是第几个职工，以及此职工的
  //   全部数据。如没有，就输出“无此人”。可以反复多次查询，如果输入查找的职工号为0，就结束查询。
  std::vector<Staff* > newStaff;
  staff_file.load(filename, newStaff);

  auto temp_staff = [=](const std::string &num){ 
    bool exist = false;
    int order = 1;
    for(std::vector<Staff *>::const_iterator ite = newStaff.begin(); ite != newStaff.end(); ite++, order++){
      if((**ite).num() == num) { exist = true; std::cout << "序号" << order << std::endl; std::cout << **ite; }
    }
    if(!exist) std::cout << "无此人" << std::endl;
   };
  // using ite_type = decltype(temp_staff);
  while(true) {
    std::cout << "输入查找号码: ";
    std::string num;
    std::cin >> num;
    if(std::stoi(num) == 0) break; 
    temp_staff(num);
  }

  return EXIT_SUCCESS; 
}