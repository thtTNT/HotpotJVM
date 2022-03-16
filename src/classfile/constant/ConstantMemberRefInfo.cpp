//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantMemberRefInfo.h"
#include "ConstantNameAndTypeInfo.h"

namespace classFile {
    void ConstantMemberRefInfo::readInfo(ClassReader *reader) {
        this->classIndex = reader->readUint16();
        this->nameAndTypeIndex = reader->readUint16();
    }

    ConstantMemberRefInfo::ConstantMemberRefInfo(unsigned short type, ConstantPool *constantPool) : ConstantInfo(type) {
        this->constantPool = constantPool;
    }

    std::string ConstantMemberRefInfo::getClassName() {
        return this->constantPool->getClassName(this->classIndex);
    }

    std::string ConstantMemberRefInfo::getName() {
        return ((ConstantNameAndTypeInfo *) this->constantPool->constantInfoList[this->nameAndTypeIndex])->getName();
    }

    std::string ConstantMemberRefInfo::getDescription() {
        return ((ConstantNameAndTypeInfo *) this->constantPool->constantInfoList[this->nameAndTypeIndex])->getDescription();
    }

}