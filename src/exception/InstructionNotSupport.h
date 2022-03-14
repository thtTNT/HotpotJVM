//
// Created by 屠昊天 on 2022/3/14.
//

#ifndef HOTPOTJVM_INSTRUCTIONNOTSUPPORT_H
#define HOTPOTJVM_INSTRUCTIONNOTSUPPORT_H

#include <exception>

class InstructionNotSupport : public std::exception {
public:
    unsigned char opcode;

    InstructionNotSupport(unsigned char opcode);
};


#endif //HOTPOTJVM_INSTRUCTIONNOTSUPPORT_H
