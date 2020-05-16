'''
@Description: 
@LastEditors: liukai
@Date: 2020-05-08 08:28:10
@LastEditTime: 2020-05-16 22:35:42
@FilePath: /实验报告6/tasks.py
'''
from subprocess import run
run('g++ Main.cpp -o Main -std=c++11 -g ', shell='True') # && ./Organism
# run('g++ Ant.cpp -o Ant -std=c++11 -g ', shell='True') # && ./Organism