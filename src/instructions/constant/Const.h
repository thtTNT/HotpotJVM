//
// Created by 屠昊天 on 2022/3/13.
//

#ifndef HOTPOTJVM_CONST_H
#define HOTPOTJVM_CONST_H

#include "../base/Instruction.h"

class ACONST_NULL : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DCONST_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class DCONST_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FCONST_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FCONST_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class FCONST_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_M1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_2 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_3 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_4 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class ICONST_5 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LCONST_0 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};

class LCONST_1 : public NoOperandsInstruction {
    void execute(Frame *frame) override;
};


#endif //HOTPOTJVM_CONST_H
