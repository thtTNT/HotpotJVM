//
// Created by 屠昊天 on 2022/3/19.
//

#ifndef HOTPOTJVM_ARRAYSTORE_H
#define HOTPOTJVM_ARRAYSTORE_H

#include "../base/Instruction.h"

class AASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class BASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class CASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class IASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class SASTORE : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

#endif //HOTPOTJVM_ARRAYSTORE_H
