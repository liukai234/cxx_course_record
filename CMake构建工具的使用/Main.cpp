/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-13 20:39:06
 * @LastEditTime: 2020-04-16 16:59:04
 * @FilePath: /testCmake/Main.cpp
 */
#include "Message.hpp"

#include <cstdlib>
#include <iostream>

int main() {
  std::cout << __FILE__<< " " << __LINE__ << " " << __func__ << std::endl;
  Message message("Hello, CMake World!");
  std::cout << message << std::endl;
  message.reset("reset_Hello");
  std::cout << message << std::endl;

  return EXIT_SUCCESS;
}