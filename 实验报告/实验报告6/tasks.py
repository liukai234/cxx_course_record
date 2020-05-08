'''
@Description: 
@LastEditors: liukai
@Date: 2020-05-08 08:28:10
@LastEditTime: 2020-05-08 09:44:46
@FilePath: /实验报告6/tasks.py
'''
from subprocess import run
run('g++ Organism.cpp -o Organism -std=c++11', shell='True') # && ./Organism