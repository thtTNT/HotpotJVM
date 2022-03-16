//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_INVOKE_H
#define HOTPOTJVM_INVOKE_H


#include "../base/Instruction.h"

class INVOKE_SPECIAL : public Index16Instruction{
public:
    void execute(Frame *frame) override;
};

class INVOKE_VIRTUAL : public Index16Instruction{
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_INVOKE_H
