/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 14:39:28
 * @LastEditTime: 2020-04-30 15:28:31
 * @FilePath: /UNIX网络编程/TCP客户_服务器模型/echosrv.c
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
    int listenfd;
    if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = PF_INET;
    servaddr.sin_port = htons(5188);

    // 指定任意地址
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 显示指定地址
    // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);
    
    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        ERR_EXIT("bind");
    }

    // 监听  变为被动套接字（被动连接），否则为主动套接字（主动连接）
    // SOMAXCONN 未完成连接队列和已完成队列总和
    if(listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }
    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn;
    if((conn = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen)) < 0){
        ERR_EXIT("accept");
    }
    char recvbuf[1024];
    while(1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = read(conn, recvbuf, sizeof(recvbuf));
        fputs(recvbuf, stdout);
        write(conn, recvbuf, ret);
    }
    close(conn);
    close(listenfd);
    return 0;
}