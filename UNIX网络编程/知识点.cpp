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

// 地址转换函数
