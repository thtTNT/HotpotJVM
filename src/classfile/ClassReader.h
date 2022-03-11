//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_CLASSREADER_H
#define HOTPOTJVM_CLASSREADER_H


#include <vector>
#include <string>

class ClassReader {
private:
    int index;
    std::string *bs;
    int length;
public:
    explicit ClassReader(std::string *bs);

    unsigned char readUint8();

    unsigned short readUint16();

    unsigned int readUint32();

    unsigned long readUint64();

    std::vector<unsigned short> readUint16s();

    char *readBytes(unsigned int lenToRead);
};


#endif //HOTPOTJVM_CLASSREADER_H
