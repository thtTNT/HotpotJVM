//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_IINC_H
#define HOTPOTJVM_IINC_H


#include "../base/Instruction.h"

class IINC : public Instruction {

    void fetchOperands(ByteCodeReader *reader) override;

    void execute(Frame *frame) override;

public:
    unsigned index = 0;
    int value = 0;
};


#endif //HOTPOTJVM_IINC_H
