#include <iostream>
#include <vector>
#include <string>

// CRC-16生成多项式 (X^16+x^15+x^2+1)
const unsigned int POLY = 0x8005;
const unsigned int INIT = 0xFFFF;

// 模2除法
unsigned int crc16(const std::vector<unsigned char>& data) {
    unsigned int crc = INIT;
    for (unsigned char byte : data) {
        crc ^= byte << 8;
        for (int i = 0; i < 8; ++i) {

        }
    }
}