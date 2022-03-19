//
// Created by 屠昊天 on 2022/3/19.
//

#include "ArrayStore.h"
#include "../../exception/NullPointerException.h"
#include "../../exception/RuntimeException.h"

void checkNotNull(heap::Object *obj) {
    if (obj == nullptr) {
        throw NullPointerException();
    }
}

void checkIndex(int length, int index) {
    if (index < 0 && length >= index) {
        throw RuntimeException("ArrayIndexOutOfBoundsException");
    }
}

void IASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popInt();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getInts();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void AASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popRef();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getRefs();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void BASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popInt();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getBytes();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void CASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popInt();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getChars();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void DASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popDouble();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getDoubles();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void FASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popFloat();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getFloats();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void LASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popLong();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getLongs();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}

void SASTORE::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto value = stack->popInt();
    auto index = stack->popInt();
    auto arrayRef = stack->popRef();
    checkNotNull(arrayRef);
    auto array = arrayRef->getShorts();
    checkIndex(array->size(), index);
    (*array)[index] = value;
}
