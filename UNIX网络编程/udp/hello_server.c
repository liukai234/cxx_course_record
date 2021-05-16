#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
#define BUF_ACC 2

void error_handling(char *message);

// udp 服务端
int main(int argc, char *argv[]) {
    int serv_sock;
    char message[BUF_SIZE];
    int str_len = 0;
    socklen_t clnt_adr_sz;

    struct sockaddr_in serv_adr, clnt_adr;

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // 1. 调用socket创建套接字
    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    // 2. 调用bind为套接字分配IP地址和端口
    if(bind(serv_sock, (struct sockaddr* ) &serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    // UDP 没有 TIME_WAIT，不需要设置 SO_REUSEADDR
    while(1) {
        clnt_adr_sz = sizeof(clnt_adr);
        str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        sendto(serv_sock, message, str_len, 0, (struct sockaddr*) &clnt_adr, clnt_adr_sz);
    }

    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}