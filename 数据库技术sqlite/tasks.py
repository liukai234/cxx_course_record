'''
@Description: 
@LastEditors: liukai
@Date: 2020-05-02 22:38:42
@LastEditTime: 2020-05-03 09:28:25
@FilePath: /数据库技术sqlite/tasks.py
'''
from subprocess import run
run('g++ 基础.cpp -o test -l sqlite3 -g', shell=True)