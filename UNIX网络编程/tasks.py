'''
@Description: 
@LastEditors: liukai
@Date: 2020-04-30 14:08:59
@LastEditTime: 2020-04-30 14:11:31
@FilePath: /UNIX网络编程/tasks.py
'''

from subprocess import run
run('g++ test.cpp -o test -g',shell=True) # && ./test