//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_REM_H
#define HOTPOTJVM_REM_H

#include "../base/Instruction.h"

class DREM : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FREM : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IREM : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LREM : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_REM_H
