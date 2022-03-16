//
// Created by 屠昊天 on 2022/3/12.
//

#include "LocalVars.h"

LocalVars *newLocalVars(unsigned int maxLocals) {
    if (maxLocals > 0) {
        auto localVars = new LocalVars();
        localVars->slots = std::vector<Slot>(maxLocals);
        return localVars;
    }
    return nullptr;
}

void LocalVars::setInt(unsigned int index, int value) {
    this->slots[index].num = value;
}

int LocalVars::getInt(unsigned int index) {
    return this->slots[index].num;
}

void LocalVars::setFloat(unsigned int index, float value) {
    this->slots[index].num = *(int *) &value;
}

float LocalVars::getFloat(unsigned int index) {
    return *(float *) &(this->slots[index].num);
}

void LocalVars::setLong(unsigned int index, long value) {
    this->slots[index].num = (int) value;
    this->slots[index + 1].num = (int) (value >> 32);
}

long LocalVars::getLong(unsigned int index) {
    auto low = this->slots[index].num;
    auto high = this->slots[index + 1].num;
    return ((long) high << 32) | (long) low;
}

void LocalVars::setDouble(unsigned int index, double value) {
    this->setLong(index, *(long *) &value);
}

double LocalVars::getDouble(unsigned int index) {
    auto value = (this->getLong(index));
    return *(double *) &value;
}

void LocalVars::setObject(unsigned int index, heap::Object *object) {
    this->slots[index].ref = object;
}

heap::Object *LocalVars::getObject(unsigned int index) {
    return this->slots[index].ref;
}










