/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-14 14:06:33
 * @LastEditTime: 2020-04-15 18:18:38
 * @FilePath: /testCmake/Message.hpp
 */
#pragma once

#include <iosfwd>
#include <string>

// hpp文件中放置对类的定义
class Message {
public:
  Message(const std::string &m) : message_(m) {}
  friend std::ostream &operator<<(std::ostream &os, Message &obj) {
    return obj.printObject(os);
  }
  void reset(const std::string &m);
private:
  std::string message_; // 在变量名后加下划线表示私有成员约定外部不可访问
  std::ostream &printObject(std::ostream &os);
};

