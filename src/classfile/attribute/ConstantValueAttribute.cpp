//
// Created by 屠昊天 on 2022/3/11.
//

#include "ConstantValueAttribute.h"

namespace classFile {
    void ConstantValueAttribute::readInfo(ClassReader *reader) {
        this->constantValueIndex = reader->readUint16();
    }

    ConstantValueAttribute::ConstantValueAttribute() : AttributeInfo(CONSTANT_VALUE) {

    }
}