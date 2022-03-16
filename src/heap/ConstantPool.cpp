//
// Created by 屠昊天 on 2022/3/14.
//

#include "ConstantPool.h"
#include "../classfile/constant/ConstantIntegerInfo.h"
#include "../classfile/constant/ConstantFloatInfo.h"
#include "../classfile/constant/ConstantDoubleInfo.h"
#include "../classfile/constant/ConstantLongInfo.h"
#include "../classfile/constant/ConstantStringInfo.h"
#include "SymRef.h"


heap::Constant heap::ConstantPool::getConstant(unsigned int index) {
    return this->consts[index];
}

heap::ConstantPool::ConstantPool(Class *clazz, std::vector<Constant> consts) {
    this->clazz = clazz;
    this->consts = consts;
}

heap::ConstantPool *heap::newConstantPool(Class *clazz, classFile::ConstantPool *classFileConstantPool) {
    auto count = classFileConstantPool->constantInfoList.size();
    auto heapConstantPool = new ConstantPool(clazz, std::vector<Constant>(count));
    auto consts = &(heapConstantPool->consts);
    for (int i = 1; i < count; i++) {
        auto info = classFileConstantPool->constantInfoList[i];
        switch (info->type) {
            case CONSTANT_INTEGER: {
                auto infoInteger = (classFile::ConstantIntegerInfo *) info;
                (*consts)[i].type = INT;
                (*consts)[i].intValue = infoInteger->value;
                break;
            }
            case CONSTANT_FLOAT: {
                auto infoFloat = (classFile::ConstantFloatInfo *) info;
                (*consts)[i].type = FLOAT;
                (*consts)[i].floatValue = infoFloat->value;
                break;
            }
            case CONSTANT_DOUBLE: {
                auto infoDouble = (classFile::ConstantDoubleInfo *) info;
                (*consts)[i].type = DOUBLE;
                (*consts)[i].doubleValue = infoDouble->value;
                i++;
                break;
            }
            case CONSTANT_LONG: {
                auto infoLong = (classFile::ConstantLongInfo *) info;
                (*consts)[i].type = LONG;
                (*consts)[i].longValue = infoLong->value;
                i++;
                break;
            }
            case CONSTANT_STRING: {
                auto infoString = (classFile::ConstantStringInfo *) info;
                (*consts)[i].type = STRING;
                (*consts)[i].stringValue = infoString->getValue();
                break;
            }
            case CONSTANT_CLASS: {
                auto infoClass = (classFile::ConstantClassInfo *) info;
                (*consts)[i].type = CLASS;
                (*consts)[i].symRef = heap::newClassRef(heapConstantPool, *infoClass);
                break;
            };
            case CONSTANT_FIELD_REF: {
                auto infoField = (classFile::ConstantFieldRefInfo *) info;
                (*consts)[i].type = FIELD_REF;
                (*consts)[i].symRef = heap::newFieldRef(heapConstantPool, *infoField);
                break;
            }
            case CONSTANT_METHOD_REF: {
                auto infoMethod = (classFile::ConstantMethodRefInfo *) info;
                (*consts)[i].type = METHOD_REF;
                (*consts)[i].symRef = heap::newMethodRef(heapConstantPool, *infoMethod);
                break;
            }
            case CONSTANT_INTERFACE_METHOD_REF: {
                auto infoInterfaceMethod = (classFile::ConstantInterfaceMethodRefInfo *) info;
                (*consts)[i].type = INTERFACE_METHOD_REF;
                (*consts)[i].symRef = heap::newInterfaceMethodRef(heapConstantPool, *infoInterfaceMethod);
                break;
            }
            default: {
                // TODO
            }
        }
    }
    return heapConstantPool;
}
