cmake -G "MinGW Makefiles" .   // 建立build文件夹，之后使用cmake -G "MinGW Makefiles" ..    
mingw32-make   
我将mingw32-make的文件拷贝到了cmake/bin/make.exe，这样可以直接使用make命令

---

cmake_minimum_required (VERSION 3.19)   
project (Main.cpp)   

set(CMAKE_C_COMPILER gcc)   
set(CMAKE_CXX_COMPILER g++)   

add_executable (Main Main.cpp)

---

cmake-gui 中的生成表示生成makefile文件