/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 14:21:02
 * @LastEditTime: 2020-05-06 09:30:47
 * @FilePath: /p2p通信/p2pcli.c
 */

#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0) \

int main(void) {
    int sock;
    if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(5199);

    // 指定任意地址
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 显示指定地址
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);
    // 主动模式 发起连接
    if(connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        ERR_EXIT("connect");
    }

    pid_t pid;
    pid = fork();
    // 父进程接受数据&&建立连接，子进程发送数据
    if(pid == 0) { 
        char sendbuf[1024];
        memset(sendbuf, 0, sizeof(sendbuf));
        while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){
            write(sock, sendbuf, sizeof(sendbuf));
        }
    }
    else {
        char recvbuf[1024] = {0};
        read(sock, recvbuf, sizeof(recvbuf));
        printf("来自服务器: %s", recvbuf);
        memset(recvbuf, 0, sizeof(recvbuf));
    }

    close(sock);
    return 0;
}