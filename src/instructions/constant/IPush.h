//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IPUSH_H
#define HOTPOTJVM_IPUSH_H


#include "../base/Instruction.h"

class BIPUSH : public Instruction {
    char value = 0;

    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;
};

class SIPUSH : public Instruction {
    short value;

    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_IPUSH_H
