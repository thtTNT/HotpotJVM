//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_CONSTANTPOOL_H
#define HOTPOTJVM_CONSTANTPOOL_H


#include <vector>
#include "ClassReader.h"

namespace classFile {
    class ConstantInfo;

    class ConstantPool {
    public:
        std::vector<ConstantInfo *> constantInfoList;

        ConstantInfo *getConstantInfo(unsigned short index);

        std::string getClassName(unsigned short index);

        std::string getUTF8(unsigned short index);

    };

    ConstantPool *readConstantPool(ClassReader *reader);
}


#endif //HOTPOTJVM_CONSTANTPOOL_H
