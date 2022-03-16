//
// Created by 屠昊天 on 2022/3/11.
//

#include "SyntheticAttribute.h"

namespace classFile {
    void SyntheticAttribute::readInfo(ClassReader *reader) {
    }

    SyntheticAttribute::SyntheticAttribute() : AttributeInfo(SYNTHETIC) {

    }
}
