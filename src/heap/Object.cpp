//
// Created by 屠昊天 on 2022/3/11.
//

#include "Object.h"
#include "Class.h"


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
