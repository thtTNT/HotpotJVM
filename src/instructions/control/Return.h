//
// Created by 屠昊天 on 2022/3/18.
//

#ifndef HOTPOTJVM_RETURN_H
#define HOTPOTJVM_RETURN_H


#include "../base/Instruction.h"

class RETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class DRETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class ARETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class FRETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class IRETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class LRETURN : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_RETURN_H
