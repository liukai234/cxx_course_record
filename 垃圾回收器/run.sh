#!/bin/bash

printf "Shell Script running...\n" && 

g++ main.cpp ManageAllocation.cpp Object.cpp -o test -std=c++14 &&
mkdir out &&
mv test out/test &&
out/test &&

printf "Shell Script end\n"

# chmod u+x file # 赋予user执行权限 drwxrwxrwx
# d 表示目录