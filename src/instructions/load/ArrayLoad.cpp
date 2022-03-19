//
// Created by 屠昊天 on 2022/3/19.
//

#include "ArrayLoad.h"
#include "../../exception/NullPointerException.h"
#include "../../exception/RuntimeException.h"

void AALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getRefs();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushRef((*refs)[index]);
}


void BALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getBytes();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushInt((*refs)[index]);
}

void CALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getChars();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushInt((*refs)[index]);
}

void DALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getDoubles();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushDouble((*refs)[index]);
}

void FALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getFloats();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushFloat((*refs)[index]);
}

void IALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getInts();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushInt((*refs)[index]);
}

void LALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getLongs();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushLong((*refs)[index]);
}

void SALOAD::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }
    auto refs = arrayRef->getShorts();
    if (index < 0 || index >= arrayRef->arrayLength()) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
    stack->pushInt((*refs)[index]);
}
