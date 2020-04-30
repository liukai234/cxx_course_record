/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 14:21:02
 * @LastEditTime: 2020-04-30 15:32:25
 * @FilePath: /UNIX网络编程/TCP客户_服务器模型/echocli.c
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
    servaddr.sin_port = htons(5188);

    // 指定任意地址
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 显示指定地址
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);
    // 主动模式 发起连接
    if(connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        ERR_EXIT("connect");
    }
    char sendbuf[1024] = {0};
    char recvbuf[1024] = {0};
    while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){
        write(sock, sendbuf, strlen(sendbuf));
        read(sock, recvbuf, sizeof(recvbuf));
        fputs(recvbuf, stdout);
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(recvbuf, 0, sizeof(recvbuf));
    }
    close(sock);
    return 0;
}