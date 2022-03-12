//
// Created by 屠昊天 on 2022/3/12.
//

#include "OperandStack.h"

OperandStack *newOperandStack(unsigned int maxStack) {
    if (maxStack > 0) {
        auto operandStack = new OperandStack();
        operandStack->slots = std::vector<Slot>(maxStack);
        return operandStack;
    }
    return nullptr;
}

void OperandStack::pushInt(int value) {
    this->slots[this->size].num = value;
    this->size++;
}

int OperandStack::popInt() {
    this->size--;
    return this->slots[this->size].num;
}

void OperandStack::pushFloat(float value) {
    this->slots[this->size].num = *(int *) &value;
    this->size++;
}

float OperandStack::popFloat() {
    this->size--;
    return *(float *) &(this->slots[this->size].num);
}

void OperandStack::pushLong(long value) {
    this->slots[this->size].num = (int) value;
    this->slots[this->size + 1].num = (int) (value << 32);
    this->size += 2;
}

long OperandStack::popLong() {
    this->size -= 2;
    auto low = this->slots[this->size].num;
    auto high = this->slots[this->size + 1].num;
    return static_cast<long>(high) << 32 | low;
}

void OperandStack::pushDouble(double value) {
    this->pushLong(*(long *) &value);
}

double OperandStack::popDouble() {
    auto value = this->popLong();
    return *(double *) &value;
}

void OperandStack::pushRef(Object *ref) {
    this->slots[this->size].ref = ref;
    this->size++;
}

Object *OperandStack::popRef() {
    this->size--;
    return this->slots[this->size].ref;
}












