'''
@Description: 自动化编译工具
@LastEditors: liukai
@Date: 2020-04-27 16:52:21
@LastEditTime: 2020-04-27 16:59:59
@FilePath: /实验报告4/tasks.py
'''

from subprocess import run

# args=input('附加参数:')
pre_cmd='g++ Main.cpp Staff.cpp -o Main'
args='-std=c++14'
end_cmd='' #&& ./Main
run(pre_cmd + ' ' + args + ' ' + end_cmd, shell=True)