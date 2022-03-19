//
// Created by 屠昊天 on 2022/3/19.
//

#ifndef HOTPOTJVM_ARRAYLOAD_H
#define HOTPOTJVM_ARRAYLOAD_H


#include "../base/Instruction.h"

class AALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class BALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class CALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class DALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class FALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class IALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class LALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

class SALOAD : public NoOperandsInstruction {
public:
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_ARRAYLOAD_H
