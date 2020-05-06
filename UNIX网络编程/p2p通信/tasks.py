'''
@Description: 
@LastEditors: liukai
@Date: 2020-04-30 14:08:59
@LastEditTime: 2020-05-06 09:30:13
@FilePath: /p2p通信/tasks.py
'''

from subprocess import run

run('gcc p2psrv.c -o p2psrv',shell=True)
run('gcc p2pcli.c -o p2pcli',shell=True)