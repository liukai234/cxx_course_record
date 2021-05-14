//
// Created by lk234 on 2021/5/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
#ifdef DEBUG
    printf("define DEBUG");
#endif
#ifndef DEBUG
    printf("undefine DEBUG");
#endif
}