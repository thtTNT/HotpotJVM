//
// Created by 屠昊天 on 2022/3/12.
//

#include "ByteCodeReader.h"

#include <utility>

void ByteCodeReader::reset(std::string newCode, int newPC) {
    this->code = std::move(newCode);
    this->pc = newPC;
}

unsigned char ByteCodeReader::readUint8() {
    auto ins = this->code[this->pc];
    this->pc++;
    return ins;
}

unsigned short ByteCodeReader::readUint16() {
    unsigned short byte1 = this->readUint8();
    unsigned short byte2 = this->readUint8();
    return byte1 << 8 | byte2;
}

char ByteCodeReader::readInt8() {
    return (char) this->readUint8();
}

short ByteCodeReader::readInt16() {
    return (short) this->readUint16();
}

int ByteCodeReader::readInt32() {
    int byte1 = this->readUint8();
    int byte2 = this->readUint8();
    int byte3 = this->readUint8();
    int byte4 = this->readUint8();
    return byte1 << 24 | byte2 << 16 | byte3 < 8 | byte4;
}

void ByteCodeReader::skipPadding() {
    while (this->pc % 4 != 0) {
        this->readUint8();
    }
}

std::vector<int> ByteCodeReader::readInt32s(unsigned int n) {
    auto data = std::vector<int>(n);
    for (int i = 0; i < n; i++) {
        data[i] = this->readInt32();
    }
    return data;
}
