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
