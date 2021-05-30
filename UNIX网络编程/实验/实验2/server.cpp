#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include "agreement.h"
#include <fstream>
#include <sstream>

typedef unsigned char uchar;
void error_handling(const std::string &buf);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    struct timeval timeout;
    fd_set reads, cpy_reads;

    socklen_t adr_sz;
    int fd_max, str_len, fd_num, i;
    char buf[BUF_LEN];

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr* ) &serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    int option = true;
    int optlen = sizeof(option);
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (void*)&option, optlen);

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    std::ofstream user_out("user.txt", std::fstream::app);
    std::ifstream user_in("user.txt");
    std::string compare_string;
    std::string origin_string;
    std::ostringstream oss;

    while(1) {
        cpy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 5000;

        if((fd_num = select(fd_max + 1, &cpy_reads, 0, 0, &timeout)) == -1)
            break;
        if(fd_num == 0)
            continue;

        for(i = 0; i < fd_max + 1; i ++) {
            if(FD_ISSET(i, &cpy_reads)) {
                if(i == serv_sock) {
                    adr_sz = sizeof(clnt_adr);
                    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
                    FD_SET(clnt_sock, &reads);
                    if(fd_max < clnt_sock)
                        fd_max = clnt_sock;
                    printf("connect client: %d \n", clnt_sock);
                } else {
                    str_len = read(i, buf, BUF_LEN);
                    if(str_len == 0) {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d \n", i);
                    } else {
                        // 对协议进行处理
                        switch (buf[0]) {
                            case '0': /* login */

                                oss.str("");
                                origin_string.erase();
                                for(i = 0; i < ID_LEN; ++ i){ if(buf[ID_START + i] == '\n') break; oss << buf[ID_START + i]; }
                                origin_string = oss.str();
                                std::cout << "login_id: " << origin_string << std::endl;
                                user_in.clear();
                                while(user_in >> compare_string) {
                                    // std::cout << compare_string << std::endl;
                                    if(compare_string == origin_string) {
                                        std::cout << "id exist\n";

                                        oss.str("");
                                        origin_string.erase();
                                        for(i = 0; i < PW_LEN; ++ i){ if(buf[PW_START + i] == '\n') break; oss << buf[PW_START + i]; }
                                        origin_string = oss.str();
                                        user_in >> compare_string;

                                        if(compare_string == origin_string) {
                                            std::cout << "login_pw: " << origin_string << std::endl;
                                            std::cout << "login success\n";
                                            break;
                                        }
                                    }
                                }
                                break;
                            case '1': /* logout */ break;
                            case '2': /* sign */
                                for(i = 0; i < ID_LEN; ++ i){ if(buf[ID_START + i] == '\n') break; user_out << buf[ID_START + i]; }
                                user_out << std::endl;
                                for(i = 0; i < PW_LEN; ++ i){ if(buf[PW_START + i] == '\n') break; user_out << buf[PW_START + i]; }
                                user_out << std::endl;
                                break;
                            case '3': /* alive-time */ break;
                            case '4': /* buf-message*/
                                std::cout << "message: ";
                                for(i = 0; i < MESSAGE_LEN; ++ i){ if(buf[MESSAGE_START + i] == '\n') break; std::cout << buf[MESSAGE_START + i]; }
                                std::cout << std::endl;
                                break;
                        }
                        // write(i, buf, str_len);
                    }
                }
            }
        }
    }
    close(serv_sock);
    return 0;
}

void error_handling(const std::string &buf) {
    std::cerr << buf << '\n';
    exit(1);
}