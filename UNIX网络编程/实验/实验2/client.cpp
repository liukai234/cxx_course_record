#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include "agreement.h"

typedef unsigned char uchar;
void error_handling(const std::string &buf);

int main(int argc, char *argv[]) {
    int sock;
    char buf[BUF_LEN];

    int str_len;
    struct sockaddr_in serv_adr;

    if(argc != 3) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    if(!strcmp("localhost", argv[1])) serv_adr.sin_addr.s_addr = inet_addr("127.0.0.1");
    else serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error");
    else
        puts("connected");

    bool CLOSE = false;
    char *id = buf + ID_START;
    char *pw = buf + PW_START;
    char *message = buf + MESSAGE_START;
    while(1) {
        buf[TYPE_START] = fgetc(stdin); fgetc(stdin);
        switch (buf[0]) {
            case '0':
                /* login */
                fgets(id, ID_LEN, stdin);
                fgets(pw, PW_LEN, stdin);
                break;
            case '1':
                CLOSE = true;
                break;
            case '2': /* sign */
                fgets(id, ID_LEN, stdin);
                fgets(pw, PW_LEN, stdin);
                break;
            case '3': /* alive-time */
                // nothing to do
                break;
            case '4':
                /* buf-message */
                fgets(message, MESSAGE_LEN, stdin);
                break;
        }
        if(CLOSE) break;

        //fputs("Input buf(q to quit): ", stdout); // fflush(stdout);
        //fgets(input_index, MESSAGE_LEN, stdin); // gets has been officially removed from ISO C11 and ISO C++14, because overflow


        write(sock, buf, BUF_LEN);
        // str_len = read(sock, buf, BUF_LEN - 1);
        // buf[str_len] = 0; // break point
        // printf("buf from server: %s", buf); // fflush(stdout);
    }
    close(sock);
    return 0;

}

void error_handling(const std::string &buf) {
    std::cerr << buf << '\n';
    exit(1);
}