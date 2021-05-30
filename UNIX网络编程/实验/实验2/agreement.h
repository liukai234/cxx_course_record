#ifndef TCP_IP_AGREEMENT_H
#define TCP_IP_AGREEMENT_H

constexpr size_t TYPE_START = 0;
constexpr size_t TYPE_LEN = 1;
constexpr size_t ID_START = TYPE_START + TYPE_LEN;
constexpr size_t ID_LEN = 16;
constexpr size_t PW_START = ID_START + ID_LEN;
constexpr size_t PW_LEN = 16;
constexpr size_t MESSAGE_START = PW_START + PW_LEN;
constexpr size_t MESSAGE_LEN = 128;
constexpr size_t BUF_LEN = TYPE_LEN + ID_LEN + PW_LEN + MESSAGE_LEN; // 1 + 16 + 16 + 1 + 128

constexpr int ALIVE_TIME = 5000;
constexpr int BUF_ACC = 2;

#endif //TCP_IP_AGREEMENT_H
