//
// Created by 屠昊天 on 2022/3/11.
//

#include "DeprecatedAttribute.h"

namespace classFile {
    void DeprecatedAttribute::readInfo(ClassReader *reader) {
    }

    DeprecatedAttribute::DeprecatedAttribute() : AttributeInfo(DEPRECATED) {
    }
}
