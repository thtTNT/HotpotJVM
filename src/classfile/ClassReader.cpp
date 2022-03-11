//
// Created by 屠昊天 on 2022/3/8.
//

#include "ClassReader.h"
#include "../exception/EndOfFileException.h"
#include <cstring>

ClassReader::ClassReader(std::string *bs) {
    this->bs = bs;
    this->index = 0;
    this->length = bs->length();
}

unsigned char ClassReader::readUint8() {
    if (length - index >= 1) {
        auto num = (unsigned char) this->bs->c_str()[index];
        index++;
        return num;
    } else {
        throw EndOfFileException();
    }
}

unsigned short ClassReader::readUint16() {
    if (length - index >= 2) {
        unsigned short num = (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        return num;
    } else {
        throw EndOfFileException();
    }
}

unsigned int ClassReader::readUint32() {
    if (length - index >= 4) {
        unsigned int num = (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        return num;
    } else {
        throw EndOfFileException();
    }
}

unsigned long ClassReader::readUint64() {
    if (length - index >= 8) {
        unsigned long num = (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        num = num * 256 + (unsigned char) bs->c_str()[index];
        index++;
        return num;
    } else {
        throw EndOfFileException();
    }
}

char *ClassReader::readBytes(unsigned int lenToRead) {
    if (lenToRead - index >= lenToRead) {
        auto result = new char[length];
        unsigned int rest = lenToRead;
        while (rest--) {
            result[lenToRead - rest - 1] = bs->c_str()[index];
            index++;
        }
        return result;
    } else {
        throw EndOfFileException();
    }
}

std::vector<unsigned short> ClassReader::readUint16s() {
    auto count = this->readUint16();
    auto result = std::vector<unsigned short>(count);
    for (int i = 0; i < count; i++) {
        result[i] = this->readUint16();
    }
    return result;
}




