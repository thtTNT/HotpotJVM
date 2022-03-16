//
// Created by 屠昊天 on 2022/3/16.
//

#include "Invoke.h"
#include <iostream>

void INVOKE_SPECIAL::execute(Frame *frame) {
    // TODO hack
    frame->operandStack->popRef();
}

void INVOKE_VIRTUAL::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto methodRef = (heap::MethodRef *) constantPool->getConstant(this->index).symRef;
    // TODO hack
    if (methodRef->getName() == "println") {
        auto stack = frame->operandStack;
        auto descriptor = methodRef->getDescription();
        if (descriptor == "(Z)V") {
            std::cout << (stack->popInt() != 0) << std::endl;
        } else if (descriptor == "(C)V") {
            std::cout << stack->popInt() << std::endl;
        } else if (descriptor == "(B)V") {
            std::cout << stack->popInt() << std::endl;
        } else if (descriptor == "(S)V") {
            std::cout << stack->popInt() << std::endl;
        } else if (descriptor == "(I)V") {
            std::cout << stack->popInt() << std::endl;
        } else if (descriptor == "(J)V") {
            std::cout << stack->popLong() << std::endl;
        } else if (descriptor == "(F)V") {
            std::cout << stack->popFloat() << std::endl;
        } else if (descriptor == "(D)V") {
            std::cout << stack->popDouble() << std::endl;
        } else {
            std::cout << "Error Print: " << methodRef->getDescription() << std::endl;
        }
        stack->popRef();
    }
}
