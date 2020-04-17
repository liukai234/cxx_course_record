/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-15 16:05:00
 * @LastEditTime: 2020-04-15 18:19:56
 * @FilePath: /testCmake/Message.cpp
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