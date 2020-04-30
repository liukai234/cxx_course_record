/*
 * @Description: 
 * @LastEditors: liukai
 * @Date: 2020-04-30 14:36:58
 * @LastEditTime: 2020-04-30 15:52:41
 * @FilePath: /UNIX网络编程/知识点.cpp
 */
#include <netinet/in.h>

// IPv4 结构体
struct scokaddr_in{
    // 整个结构体的长度
    uint8_t sin_len;
    // 指定地址家族 这里设为AF_INET(IPv4)
    sa_family_t sin_family;
    // 端口 2字节
    in_port_t sin_port;
    // IPv4的地址 4字节
    struct in_addr sin_addr;
    // 一般设置为0 8字节
    char sin_zero[8];
};

// 通用地址结构
struct sockaddr_in{
    // 整个sockaddr结构体的长度
    uint8_t sin_len;
    // 指定地址家族
    sa_family_t sin_family;
    // 由family决定形式 14字节 与上边IPv4的结构体相兼容
    char sin_zero[14];
};

// 大端字节序：高地址存在低内存中 | 小端字节序：高地址存在高内存中
// 网络字节序采用大端字节序
// 主机字节序：x86为小端字节序

// 字节序转换函数
// h 代表 host n代表network s代表short l代表long
uint32_t htonl(uint32_t lostlong){}
uint16_t htons(uint16_t hostshort){}
uint32_t ntohl(uint32_t netlong){}
uint16_t ntohs(uint16_t netshort){}

#include <netinet/in.h>
#include <arpa/inet.h>
// 地址转换函数
int inet_aton(const char *cp, struct in_addr *inp){}
in_addr_t inet_addr(const char * cp){}
char *inet_ntoa(struct in_addr in){}

// 套接字类型
// 流式套接字 SOCK_STREAM 对应tcp协议：提供面向连接的，可靠的数据服务
// 数据报套接字 SOCK_DGRAM 提供无连接服务，不提供无错保证
// 原始套接字 SOCK_RAW

#include <sys/socket.h>

// domain指定通信协议族(protocol family)
// type 指定socket类型，流式套接字SOCK_STREAM，数据报套接字SOCK_DGRAM，原始套接字SOCK_RAW
// protocol 协议类型
// 成功返回非负整数，他与文件描述符类似，称为套接口描述字，简称套接字，失败返回-1
int socket(int domain, int type, int protocol){}

// sockfd socket函数要返回的套接字
// addr 要绑定的地址
// addrlen 地址长度
// 成功返回0， 失败返回-1
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){}

// 将套接字用于监听进入的连接
// sockfd socket函数返回的套接字
// 规定内核为此套接字排队的最大连接个数
int listen(int sockfd, int backlog){}

// 从已完成连接队列返回第一个连接，如果已完成连接队列为空，则阻塞
// sockfd 服务器套接字
// addr 将返回对等方的套接字地址
// addrlen 返回对等方的套接字地址长度
int accept(int sockfd, struct sockaddr * addr, socklen_t *addrlen){}