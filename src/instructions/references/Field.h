//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_INSTRUCTION_FIELD_H
#define HOTPOTJVM_INSTRUCTION_FIELD_H

#include "../base/Instruction.h"

class PUT_FIELD : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};

class GET_FIELD : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_FIELD_H
