//
// Created by 屠昊天 on 2022/3/12.
//

#ifndef HOTPOTJVM_BYTECODEREADER_H
#define HOTPOTJVM_BYTECODEREADER_H

#include <string>
#include <vector>

class ByteCodeReader {
private:
    std::string code;
public:
    unsigned int pc;

    void reset(std::string newCode, int newPC);

    unsigned char readUint8();

    char readInt8();

    unsigned short readUint16();

    short readInt16();

    int readInt32();

    std::vector<int> readInt32s(unsigned int n);

    void skipPadding();
};


#endif //HOTPOTJVM_BYTECODEREADER_H
