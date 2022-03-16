//
// Created by 屠昊天 on 2022/3/15.
//

#include "Slots.h"

void heap::Slots::setInt(unsigned int index, int value) {
    this->slots[index].intValue = value;
}

int heap::Slots::getInt(unsigned int index) {
    return this->slots[index].intValue;
}

void heap::Slots::setFloat(unsigned int index, float value) {
    this->slots[index].floatValue = value;
}

float heap::Slots::getFloat(unsigned int index) {
    return this->slots[index].floatValue;
}

void heap::Slots::setLong(unsigned int index, long value) {
    this->slots[index].intValue = (int) value;
    this->slots[index + 1].intValue = (int) (value >> 32);
}

long heap::Slots::getLong(unsigned int index) {
    auto low = this->slots[index].intValue;
    auto high = this->slots[index + 1].intValue;
    return ((long) high << 32) | (long) low;
}

void heap::Slots::setDouble(unsigned int index, double value) {
    this->setLong(index, *(long *) &value);
}

double heap::Slots::getDouble(unsigned int index) {
    auto value = (this->getLong(index));
    return *(double *) &value;
}

void heap::Slots::setRef(unsigned int index, Object *object) {
    this->slots[index].ref = object;
}

heap::Object *heap::Slots::getRef(unsigned int index) {
    return this->slots[index].ref;
}

heap::Slots::Slots(int slotCount) {
    this->slots = std::vector<heap::Slot>(slotCount);
}
