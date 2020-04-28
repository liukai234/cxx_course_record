'''
@Description: 
@LastEditors: liukai
@Date: 2020-04-28 14:30:03
@LastEditTime: 2020-04-28 16:33:45
@FilePath: /C++课程学习记录/实验报告/实验报告4/tasks.py
'''

from subprocess import run
pre_cmd = 'g++ Main.cpp -o Main'
args=''
end_cmd = '&&./Main' # 
run(pre_cmd + ' ' + args + ' ' + end_cmd, shell=True)