/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-15 16:05:00
 * @LastEditTime: 2020-04-24 10:16:51
 * @FilePath: /C++课程学习记录/CMake构建工具的使用/Message.cpp
 */
#include "Message.hpp"
#include <iostream>
#include <string>

std::ostream &Message::printObject(std::ostream &os) {
  os << "Message.cpp_output: " << message_;
  return os;
}
void Message::reset(const std::string &m){
  message_ = m;
}