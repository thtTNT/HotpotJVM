//
// Created by 屠昊天 on 2022/3/16.
//

#ifndef HOTPOTJVM_CHECKCAST_H
#define HOTPOTJVM_CHECKCAST_H


#include "../base/Instruction.h"

class CHECK_CAST : public Index16Instruction {
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_CHECKCAST_H
