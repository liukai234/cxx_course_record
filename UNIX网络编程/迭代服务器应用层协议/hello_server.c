#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256
#define BUF_ACC 2

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[BUF_SIZE];
    int str_len = 0;
    int recv_len = 0;

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // 1. 调用socket创建套接字
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // 2. 调用bind为套接字分配IP地址和端口
    if(bind(serv_sock, (struct sockaddr* ) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    // 3. 调用listen转为可接受请求状态
    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    clnt_addr_size = sizeof(clnt_addr);

    for(int i = 0; i < BUF_ACC; ++ i) {
        // 4. 调用accept函数受理连接请求
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

        if(clnt_sock == -1)
            error_handling("accept() error");
        else
            printf("connected client %d \n", i + 1);


        // 第一字节表示字符串大小
        unsigned char tmp;
        while(read(clnt_sock, &tmp, 1) != 0){
            str_len = (int)tmp;
            printf("message length(0 ~ 255): %d\n", str_len);
            read(clnt_sock, message, str_len);
            message[str_len] = '\0';
            printf("message from client is ready: %s\n", message);
        }

        /*
        // 前四字节表示字符串大小
        while(read(clnt_sock, &str_len, 4) != 0) {
            printf("message length(0 ~ 2^32-1): %d\n", str_len);
            read(clnt_sock, message, str_len);
            message[str_len] = '\0';
            printf("message from client is ready: %s\n", message);
        }
        */
        close(clnt_sock);
        printf("clnt_sock %d release\n", i + 1);
    }

    close(serv_sock);
    printf("serv_sock release\n");
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}