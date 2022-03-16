//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_STATIC_H
#define HOTPOTJVM_STATIC_H


#include "../base/Instruction.h"

class PUT_STATIC : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};

class GET_STATIC : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_STATIC_H
