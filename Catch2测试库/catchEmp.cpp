/*
 * @Description:
 * @LastEditors: liukai
 * @Date: 2020-04-16 18:33:04
 * @LastEditTime: 2020-04-16 18:37:45
 * @FilePath: /C++课程学习记录/Catch2测试库/catchEmp.cpp
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// TEST_CASE 测试用例
TEST_CASE("TEST_CHECK") {
    // SECTION 测试区段
    int x = 1;
    ++x;
    CHECK(x == 2); 
    // REQUIRE() 断言
}