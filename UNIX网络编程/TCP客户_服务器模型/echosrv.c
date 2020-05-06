/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 14:39:28
 * @LastEditTime: 2020-05-06 08:35:21
 * @FilePath: /TCP客户_服务器模型/echosrv.c
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

void do_service(int conn) {
    char recvbuf[1024];

    while(1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = read(conn, recvbuf, sizeof(recvbuf));

        // 捕获客户端的退出信息
        if(ret == 0) {
            printf("clint disconnect\n");
            break;
        }
        if(ret == -1) { ERR_EXIT("read"); }

        fputs(recvbuf, stdout);
        write(conn, recvbuf, ret);
    }
}

int main(void) {
    int listenfd;
    if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = PF_INET;

    /* POSIX.1g specifies this type name for the `sa_family' member.  */
    typedef unsigned short int sa_family_t;
    servaddr.sin_port = htons(5199);

    // 指定任意地址
    // unsigned int 为 long             htonl
    // unsigned short int 为 short      htons
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 显示指定地址
    // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);
    
    // 服务器端尽可能使用resueaddr选项 地址重复利用
    // 在绑定之前尽可能调用setsockopt来设置reuseaddr套接字选项
    // 使用reuseaddr选项可以不必等待time_wait状态消失就可以重启服务器
    // 查看端口占用状态 netstat -an | grep TIME_WATE
    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        ERR_EXIT("setsockopt");
    }
    /* Give the socket FD the local address ADDR (which is LEN bytes long).  */
    // extern int bind (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len)
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
    
    // 通过一个连接建立一个进程来处理并发
    pid_t pid; // pid_t: Type of process identifications.
    
    while(1) {
        // 将accept套接字放到循环中， 让多个进程建立连接
        if((conn = accept(listenfd, (struct sockaddr *)&peeraddr, &peerlen)) < 0){
            ERR_EXIT("accept");
        }
        printf("客户端ip=%s 客户端端口port=%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        /* Clone the calling process, creating an exact copy.
        Return -1 for errors, 0 to the new process,
        and the process ID of the new process to the old process.  */
        pid = fork();

        if(pid == -1) { ERR_EXIT("fork"); }

        // 对于子进程来说不需要监听；如果进程创建失败的话关闭这个套接字
        // 在do_service中捕获客户端推出信息，并结束do_service循环，一定记得退出子进程
        if(pid == 0) { close(listenfd); do_service(conn); exit(EXIT_SUCCESS); } 
        else { close(conn); }
    }

    return 0;
}