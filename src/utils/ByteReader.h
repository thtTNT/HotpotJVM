//
// Created by 屠昊天 on 2022/3/17.
//

#ifndef HOTPOTJVM_BYTEREADER_H
#define HOTPOTJVM_BYTEREADER_H

#include <string>

class ByteReader {
private:
    std::string str;
    int index = 0;
public:

    ByteReader(const std::string &str);

    unsigned char readUint8();

    unsigned short readUint16();

    unsigned int readUint32();

    void rollback(int delta);

    void setIndex(int newIndex);

    int getIndex() const;

    bool isEnd();

    const std::string &getStr() const;
};


#endif //HOTPOTJVM_BYTEREADER_H
