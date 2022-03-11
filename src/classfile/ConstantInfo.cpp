//
// Created by 屠昊天 on 2022/3/9.
//

#include "ConstantInfo.h"
#include "constant/ConstantIntegerInfo.h"
#include "constant/ConstantFloatInfo.h"
#include "constant/ConstantLongInfo.h"
#include "constant/ConstantDoubleInfo.h"
#include "constant/ConstantUTF8Info.h"
#include "constant/ConstantStringInfo.h"
#include "constant/ConstantClassInfo.h"
#include "constant/ConstantMemberRefInfo.h"
#include "../exception/ClassNotSupportException.h"
#include "constant/ConstantNameAndTypeInfo.h"

ConstantInfo::ConstantInfo(unsigned char type) {
    this->type = type;
}

ConstantInfo *readConstantInfo(ClassReader *reader, ConstantPool *constantPool) {
    auto tag = reader->readUint8();
    switch (tag) {
        case CONSTANT_INTEGER: {
            auto *integerInfo = new ConstantIntegerInfo();
            integerInfo->readInfo(reader);
            return integerInfo;
        }
        case CONSTANT_FLOAT: {
            auto *floatInfo = new ConstantFloatInfo();
            floatInfo->readInfo(reader);
            return floatInfo;
        }
        case CONSTANT_LONG: {
            auto *longInfo = new ConstantLongInfo();
            longInfo->readInfo(reader);
            return longInfo;
        }
        case CONSTANT_DOUBLE: {
            auto *doubleInfo = new ConstantDoubleInfo();
            doubleInfo->readInfo(reader);
            return doubleInfo;
        }
        case CONSTANT_UTF8: {
            auto *utf8Info = new ConstantUTF8Info();
            utf8Info->readInfo(reader);
            return utf8Info;
        }
        case CONSTANT_STRING: {
            auto *stringInfo = new ConstantStringInfo(constantPool);
            stringInfo->readInfo(reader);
            return stringInfo;
        }
        case CONSTANT_CLASS: {
            auto *classInfo = new ConstantClassInfo(constantPool);
            classInfo->readInfo(reader);
            return classInfo;
        }
        case CONSTANT_FIELD_REF: {
            auto *fieldInfo = new ConstantFieldRefInfo(constantPool);
            fieldInfo->readInfo(reader);
            return fieldInfo;
        }
        case CONSTANT_METHOD_REF: {
            auto *methodInfo = new ConstantMethodRefInfo(constantPool);
            methodInfo->readInfo(reader);
            return methodInfo;
        }
        case CONSTANT_INTERFACE_METHOD_REF: {
            auto *interfaceMethodInfo = new ConstantFieldRefInfo(constantPool);
            interfaceMethodInfo->readInfo(reader);
            return interfaceMethodInfo;
        }
        case CONSTANT_NAME_AND_TYPE: {
            auto nameAndTypeInfo = new ConstantNameAndTypeInfo();
            nameAndTypeInfo->readInfo(reader);
            return nameAndTypeInfo;
        }
        default:
            throw ClassNotSupportException();
    }
}

