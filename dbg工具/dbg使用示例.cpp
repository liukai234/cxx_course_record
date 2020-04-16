/*
 * @Author: your name
 * @Date: 2020-04-09 14:35:01
 * @LastEditTime: 2020-04-16 18:36:27
 * @LastEditors: liukai
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/dbg工具/dbg使用示例.cpp
 */
#include <vector>
#include <utility>
#include <string>
#include "dbg.h"
#define DBG_MACRO_DISABLE
// You can use "dbg(..)" in expressions:
int factorial(int n) {
  if (dbg(n <= 1)) {
    return dbg(1);
  } else {
    return dbg(n * factorial(n - 1));
  }
}

int main() {
  std::string message = "hello";
  dbg(message);  // [example.cpp:15 (main)] message = "hello" (std::string)

  const int a = 2;
  const int b = dbg(3 * a) + 1;  // [example.cpp:18 (main)] 3 * a = 6 (int)

  std::vector<int> numbers{b, 13, 42};
  dbg(numbers);  // [example.cpp:21 (main)] numbers = {7, 13, 42} (size: 3) (std::vector<int>)

  dbg("this line is executed");  // [example.cpp:23 (main)] this line is executed

  factorial(4);
  dbg(1);

  std::pair<std::string, int> tx = std::make_pair("string", 2);
  dbg(tx);

  return 0;
}