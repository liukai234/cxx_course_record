'''
@Description: 
@LastEditors: liukai
@Date: 2020-05-02 22:38:42
@LastEditTime: 2020-05-02 22:40:19
@FilePath: /数据库技术sqlite/tasks.py
'''
from subprocess import run
run('g++ test.cpp -o test -l sqlite3', shell=True)