//
// Created by lk234 on 2021/5/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void keyctrl(int sig) {
    char c;
    printf("y for quit: ");
    scanf("%c", &c);

    if(sig == SIGINT && (c == 'y' || c == 'Y')) {
        printf("exit\n");
        exit(2);
    }
}

int main() {
    signal(SIGINT, keyctrl);
    int status;
    pid_t pid = fork();
    if(pid == 0) {
        sleep(5);
        printf("calculation is complete\n");
    }
    else {
        while(!waitpid(-1, &status, WNOHANG)) {
            sleep(1);
            printf("."); fflush(stdout);
        }
    }
}