//
// Created by 屠昊天 on 2022/3/8.
//

#include "ConstantPool.h"
#include "ConstantInfo.h"
#include "constant/ConstantStringInfo.h"
#include "constant/ConstantUTF8Info.h"
#include "constant/ConstantClassInfo.h"
#include "../exception/ConstantNotFound.h"

ConstantPool *readConstantPool(ClassReader *reader) {
    auto constantPool = new ConstantPool();
    auto count = reader->readUint16();
    constantPool->constantInfoList = std::vector<ConstantInfo *>(count);
    for (int index = 1; index < count; index++) {
        constantPool->constantInfoList[index] = readConstantInfo(reader, constantPool);
        switch (constantPool->constantInfoList[index]->type) {
            case CONSTANT_LONG:
            case CONSTANT_DOUBLE:
                index++;
                break;
        }
    }
    return constantPool;
}

ConstantInfo *ConstantPool::getConstantInfo(unsigned short index) {
    if (index > this->constantInfoList.size() - 1) {
        throw ConstantNotFound();
    }
    auto constantInfo = this->constantInfoList[index];
    if (constantInfo == nullptr) {
        throw ConstantNotFound();
    }
    return constantInfo;
}

std::string ConstantPool::getClassName(unsigned short index) {
    return ((ConstantClassInfo *) this->constantInfoList[index])->getName();
}

std::string ConstantPool::getUTF8(unsigned short index) {
    return ((ConstantUTF8Info *) this->constantInfoList[index])->value;
}
