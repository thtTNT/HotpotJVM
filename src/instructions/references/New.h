//
// Created by 屠昊天 on 2022/3/15.
//

#ifndef HOTPOTJVM_NEW_H
#define HOTPOTJVM_NEW_H


#include "../base/Instruction.h"

class NEW : public Index16Instruction {

public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_NEW_H
