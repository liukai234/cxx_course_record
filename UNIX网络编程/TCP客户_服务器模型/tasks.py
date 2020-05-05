'''
@Description: 
@LastEditors: liukai
@Date: 2020-04-30 14:08:59
@LastEditTime: 2020-05-04 10:17:13
@FilePath: /UNIX网络编程/TCP客户_服务器模型/tasks.py
'''

from subprocess import run

run('gcc echosrv.c -o echosrv',shell=True)
run('gcc echocli.c -o echocli',shell=True)