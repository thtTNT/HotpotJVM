//
// Created by 屠昊天 on 2022/3/12.
//

#ifndef HOTPOTJVM_OPERANDSTACK_H
#define HOTPOTJVM_OPERANDSTACK_H

#include<vector>
#include "Slot.h"

class OperandStack {
private:
    unsigned int size;
public:
    std::vector<Slot> slots;

    void pushInt(int value);

    int popInt();

    void pushFloat(float value);

    float popFloat();

    void pushLong(long value);

    long popLong();

    void pushDouble(double value);

    double popDouble();

    void pushRef(heap::Object *ref);

    heap::Object *popRef();

    void pushSlot(Slot slot);

    Slot popSlot();
};

OperandStack *newOperandStack(unsigned int maxStack);


#endif //HOTPOTJVM_OPERANDSTACK_H
