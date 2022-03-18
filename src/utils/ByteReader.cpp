//
// Created by 屠昊天 on 2022/3/17.
//

#include "ByteReader.h"

unsigned char ByteReader::readUint8() {
    if (index >= this->str.length()) {
        return 0;
    }
    auto byte = this->str[index];
    index++;
    return byte;
}

unsigned short ByteReader::readUint16() {
    if (index >= this->str.length()) {
        return 0;
    }
    auto byte1 = this->str[index];
    index++;
    auto byte2 = this->str[index];
    index++;
    return (byte1 << 8) | byte2;
}

unsigned int ByteReader::readUint32() {
    if (index >= this->str.length()) {
        return 0;
    }
    auto byte1 = this->str[index];
    index++;
    auto byte2 = this->str[index];
    index++;
    auto byte3 = this->str[index];
    index++;
    return (((byte1 << 8) | byte2) << 8) | byte3;
}

void ByteReader::rollback(int delta) {
    if (delta > index) {
        this->index = 0;
    } else {
        this->index -= delta;
    }
}

ByteReader::ByteReader(const std::string &str) : str(str) {}

void ByteReader::setIndex(int newIndex) {
    this->index = newIndex;
}

int ByteReader::getIndex() const {
    return index;
}

const std::string &ByteReader::getStr() const {
    return str;
}

bool ByteReader::isEnd() {
    return this->index >= this->str.length();
}
