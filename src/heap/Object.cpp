//
// Created by 屠昊天 on 2022/3/11.
//

#include "Object.h"
#include "Class.h"
#include "Field.h"
#include "../exception/RuntimeException.h"


heap::Class *heap::Object::getClass() const {
    return clazz;
}

heap::Slots *heap::Object::getFields() const {
    return fields;
}

heap::Object::Object(heap::Class *clazz) : clazz(clazz) {
    this->fields = new Slots(clazz->instanceSlotCount);
}

bool heap::Object::isInstanceOf(heap::Class *other) {
    return other->isAssignableForm(this->getClass());
}

heap::Object::Object(heap::Class *clazz, int type, unsigned int count) {
    this->clazz = clazz;
    this->type = type;
    switch (type) {
        case DATA_TYPE_BYTE:
            this->bytes = new std::vector<char>(count);
            break;
        case DATA_TYPE_CHAR:
            this->chars = new std::vector<unsigned short>(count);
            break;
        case DATA_TYPE_SHORT:
            this->shorts = new std::vector<short>(count);
            break;
        case DATA_TYPE_INT:
            this->ints = new std::vector<int>(count);
            break;
        case DATA_TYPE_LONG:
            this->longs = new std::vector<long>(count);
            break;
        case DATA_TYPE_FLOAT:
            this->floats = new std::vector<float>(count);
            break;
        case DATA_TYPE_DOUBLE:
            this->doubles = new std::vector<double>(count);
            break;
        case DATA_TYPE_OBJECT:
            this->refs = new std::vector<Object *>(count);
            break;
    }
}

int heap::Object::arrayLength() {
    switch (this->type) {
        case DATA_TYPE_BYTE:
            return this->bytes->size();
        case DATA_TYPE_CHAR:
            return this->chars->size();
        case DATA_TYPE_SHORT:
            return this->shorts->size();
        case DATA_TYPE_INT:
            return this->ints->size();
        case DATA_TYPE_LONG:
            return this->longs->size();
        case DATA_TYPE_FLOAT:
            return this->floats->size();
        case DATA_TYPE_DOUBLE:
            return this->doubles->size();
        case DATA_TYPE_OBJECT:
            return this->refs->size();
        default:
            throw RuntimeException("Try to get the length of non array object");
    }
}

std::vector<char> *heap::Object::getBytes() const {
    return bytes;
}

std::vector<short> *heap::Object::getShorts() const {
    return shorts;
}

std::vector<int> *heap::Object::getInts() const {
    return ints;
}

std::vector<long> *heap::Object::getLongs() const {
    return longs;
}

std::vector<unsigned short> *heap::Object::getChars() const {
    return chars;
}

std::vector<float> *heap::Object::getFloats() const {
    return floats;
}

std::vector<double> *heap::Object::getDoubles() const {
    return doubles;
}

std::vector<heap::Object *> *heap::Object::getRefs() const {
    return refs;
}

void heap::Object::setRefVar(std::string name, std::string descriptor, Object *ref) {
    auto field = this->clazz->getField(name, descriptor, false);
    auto slots = this->fields;
    slots->setRef(field->slotId, ref);
}

heap::Object *heap::Object::getRefVar(std::string name, std::string descriptor) {
    auto field = this->clazz->getField(name, descriptor, false);
    return this->getFields()->getRef(field->slotId);
}

