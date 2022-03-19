//
// Created by 屠昊天 on 2022/3/19.
//

#ifndef HOTPOTJVM_ARRAY_H
#define HOTPOTJVM_ARRAY_H

#include "../base/Instruction.h"

const int AT_BOOLEAN = 4;
const int AT_CHAR = 5;
const int AT_FLOAT = 6;
const int AT_DOUBLE = 7;
const int AT_BYTE = 8;
const int AT_SHORT = 9;
const int AT_INT = 10;
const int AT_LONG = 11;

heap::Class *getPrimitiveArrayClass(heap::ClassLoader *loader, unsigned char aType);

class NEW_ARRAY : public Instruction {
private:
    int aType;
public:
    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;

};

class ANEW_ARRAY : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};

class ARRAY_LENGTH : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class MULTI_ANEW_ARRAY : public Instruction {
private:
    unsigned index;
    unsigned short dimensions;
public:
    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_ARRAY_H
