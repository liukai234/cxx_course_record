#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];

    int str_len;

    if(argc != 3) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // 1. 调用socket创建套接字
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    while(1) {
        fputs("input str_len(0 to quit): ", stdout);
        scanf("%d", &str_len);
        getchar();
        if(0 == str_len) {
            break;
        }

        // 第一字节表示字符串大小
        message[0] = (char)str_len;
        char* str_start = message + 1;
        fgets(str_start, BUF_SIZE - 1, stdin);
        message[str_len + 1] = '\0';
        puts(message);

        write(sock, message, strlen(message));
        /*
        // 前四字节表示字符串长度
        for (int i = 0; i < 4; i++)
        {
            message[i] = (str_len >> (8 * i)) & 0xff;
        }
        char *str_start = message + 4;
        fgets(str_start, BUF_SIZE - 1, stdin);
        message[str_len + 4] = '\0';
        puts(message);

        write(sock, message, str_len + 4);
        */
    }
    close(sock);
    return 0;

}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}