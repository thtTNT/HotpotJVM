//
// Created by 屠昊天 on 2022/3/14.
//

#include "Field.h"

namespace heap {
    std::vector<Field *> newFields(Class *clazz, std::vector<classFile::MemberInfo *> classFileFields) {
        auto fields = std::vector<Field *>(classFileFields.size());
        for (int i = 0; i < classFileFields.size(); i++) {
            fields[i] = new Field();
            fields[i]->clazz = clazz;
            fields[i]->copyMemberInfo(classFileFields[i]);
        }
        return fields;
    }

    bool Field::isPublic() {
        return this->accessFlags & ACC_PUBLIC;
    }

    bool Field::isPrivate() {
        return this->accessFlags & ACC_PRIVATE;
    }

    bool Field::isProtected() {
        return this->accessFlags & ACC_PROTECTED;
    }

    bool Field::isStatic() {
        return this->accessFlags & ACC_STATIC;
    }

    bool Field::isFinal() {
        return this->accessFlags & ACC_FINAL;
    }

    bool Field::isVolatile() {
        return this->accessFlags & ACC_VOLATILE;
    }

    bool Field::isTransient() {
        return this->accessFlags & ACC_TRANSIENT;
    }

    bool Field::isSynthetic() {
        return this->accessFlags & ACC_SYNTHETIC;
    }

    bool Field::isEnum() {
        return this->accessFlags & ACC_ENUM;
    }

    bool Field::isLongOrDouble() {
        return this->descriptor == "J" || this->descriptor == "D";
    }

    unsigned int Field::getConstValueIndex() const {
        return constValueIndex;
    }

    void Field::copyAttribute(classFile::MemberInfo classFileMemberInfo) {
        auto attribute = classFileMemberInfo.getConstantValueAttribute();
        if (attribute != nullptr) {
            this->constValueIndex = attribute->constantValueIndex;
        }
    }

    bool Field::isAccessibleTo(Class *clazz) {
        if (this->isPublic()) {
            return true;
        }
        if (this->isProtected()) {
            return clazz == this->clazz || clazz->isSubClassOf(this->clazz) ||
                   this->clazz->getPackageName() == clazz->getPackageName();
        }
        if (!this->isPrivate()) {
            return clazz->getPackageName() == this->clazz->getPackageName();
        }
        return this->clazz == clazz;
    }
}