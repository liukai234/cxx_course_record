cmake_minimum_required(VERSION 3.16)
project(tmp)

set(CMAKE_C_STANDARD 11) # C99 C11
set(CMAKE_CXX_STANDARD 11) # CXX11

set(CMAKE_C_FLAGS "-DDEBUG -O0 ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-DDEBUG -O0 ${CMAKE_CXX_FLAGS}")

add_executable(fork fork.c)

# add_executable(hello_server hello_server.c)
# add_executable(hello_client hello_client.c)

# add 同时修改C和C++两个编译器
# add_compile_definitions(DEBUG)
# add_compile_options(-O0)
# set 可以分别设置 C_FLAGS 和 CXX_FLAGS
# set(CMAKE_C_FLAGS "-DDEBUG -O0 ${CMAKE_C_FLAGS}")

# aux_source_directory 会查找指定目录下的所有源文件，然后将结果存进指定变量名
# aux_source_directory(<dir> <variable>)
# aux_source_directory(. DIR_SRCS)
# add_executable(Demo ${DIR_SRCS})