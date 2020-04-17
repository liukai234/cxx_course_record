# 需要CMake的最低版本
cmake_minimum_required(VERSION 3.5)

# 指定项目名和受支持的编程语言
project(Main LANGUAGES CXX) # LANGUAGES CXX

add_definitions("-std=c++11")

# 设定编译参数
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
    # message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    # message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
    message(STATUS "The C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}") # The C++ compiler version is:
endif()

# 设置 USE_LIBRATY 变量
# [注] 对于终端可选选项来说该选项是常量
# set(USE_LIBRARY OFF)

# 使用option()可以是变量的值可以通过 cmake 的 -D 选项将信息传递给 CMake 来切换库的行为
# 设定USE_LIBRARY默认值为OFF
# [注] 必须先设定 USE_LIBRARY 的值，对于终端来说该选项是变量，且该变量之前不能被set指定
option(USE_LIBRARY "Compile sources into a library?" ON)

# 输出到终端，并附加变量状态
message(STATUS "USE_LIBRARY STATUS: ${USE_LIBRARY}") # Compile sources into a library?

# 使用 BUILD_SHARED_LIBS(编译动态库) 后 add_library可以不填写static参数
set(BUILD_SHARED_LIBS OFF) # 编译动态库 OFF

# list APPEND 将Massage.hpp Message.cpp的信息添加到 _sources 变量中
# _sources 变量表示库的源
list(APPEND _sources Message.hpp Message.cpp)

# 前方设定library值
if(USE_LIBRARY)
    # add_library will creat a static library 添加库将创建一个静态库
    # since BUILD_SHARED_LIBS is OFF 因为BUILD_SHARED_LIBS(创建动态库)被 OFF(关闭）
    # message 变量表示将静态库的源添加到library中
    add_library(message ${_sources})

    # 生成可执行文件
    add_executable(Main Main.cpp)
    # 将静态库链接到可执行文件
    target_link_libraries(Main message)
else()
    # 生成可执行文件 直接编译，不生成库
    add_executable(Main Main.cpp ${_sources})
endif()

# 增加新的编译选项
# add_definitions("-std=c++11")

# 添加静态库
#add_library(message STATIC Message.hpp Message.cpp)

# 生成可执行文件
#add_executable(Main hello-world.cpp)

# 将静态库链接到可执行文件
#target_link_libraries(Main message)