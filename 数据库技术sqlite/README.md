<!--
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-05-02 21:06:58
 * @LastEditTime: 2020-05-02 22:20:40
 * @FilePath: /数据库技术sqlite/README.md
 -->
# SQLite 数据库
### 1. MySql咱目前啊也不太清楚，反正我目前还是很喜欢SQLite的
1. SQLite 是一个软件库，实现了自给自足的、无服务器的、零配置的、事务性的 SQL 数据库引擎。
2. SQLite 是在世界上最广泛部署的 SQL 数据库引擎。
3. SQLite 源代码不受版权限制。
### 2. 学习的话菜鸟教程上车 地址：https://www.runoob.com/sqlite/sqlite-tutorial.html
### 3. linux平台上自带的splite3的话，C++开发的时候要安装这俩个包，踩了一小小的坑
1. libsqlite3x.x86_64 : A C++ Wrapper for the SQLite3 embeddable SQL database engine
2. libsqlite3x-devel.x86_64 : Development files for libsqlite3x
### 4. 函数原型
#### 1. sqlite3_open
```cpp
sqlite3_open(const char *filename, sqlite3 **ppDb)
```
1. 该例程打开一个指向 SQLite 数据库文件的连接，返回一个用于其他 SQLite 程序的数据库连接对象。
2. 如果 filename 参数是 NULL 或 ':memory:'，那么 sqlite3_open() 将会在 RAM 中创建一个内存数据库，这只会在 session 的有效时间内持续。
3. 如果文件名 filename 不为 NULL，那么 sqlite3_open() 将使用这个参数值尝试打开数据库文件。如果该名称的文件不存在，sqlite3_open() 将创建一个新的命名为该名称的数据库文件并打开。
#### 2. sqlite3_exec
```cpp
sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
```
1. 该例程提供了一个执行 SQL 命令的快捷方式，SQL 命令由 sql 参数提供，可以由多个 SQL 命令组成。
2. 在这里，第一个参数 sqlite3 是打开的数据库对象，sqlite_callback 是一个回调，data 作为其第一个参数，errmsg 将被返回用来获取程序生成的任何错误。
3. sqlite3_exec() 程序解析并执行由 sql 参数所给的每个命令，直到字符串结束或者遇到错误为止。
#### 3. sqlite3_close()
```cpp
sqlite3_close(sqlite3*)
```
1. 该例程关闭之前调用 sqlite3_open() 打开的数据库连接。所有与连接相关的语句都应在连接关闭之前完成。
2. 如果还有查询没有完成，sqlite3_close() 将返回 SQLITE_BUSY 禁止关闭的错误消息。