<!--
 * @Author: your name
 * @Date: 2020-04-07 08:43:09
 * @LastEditTime: 2020-04-07 08:52:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++课程学习记录/stoi_string_to_int/string_to_int.md
 -->
# stoi
> C++风格

在C++中可以使用stoi <头文件string>来转int，这个函数相比于atoi <头文件stdlib>和strtol()两个一个最大特点是：异常！

我们知道C++相比于C语言多了异常，这也是这个函数在C++中具有的最显著功能。

例如：

```cpp
string str1 = "asq,";
// int c = stoi(str1); // 报异常
// 只要有数字就不报异常，遇到其他字符停止
string str2 = "123,12";
int c = stoi(str2);     // ok
cout << c << endl; // c = 123
```

异常如下：

```
terminate called after throwing an instance of 'std::invalid_argument'
what():  stoi
```