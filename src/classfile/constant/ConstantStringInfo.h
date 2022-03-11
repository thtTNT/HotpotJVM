//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTSTRINGINFO_H
#define HOTPOTJVM_CONSTANTSTRINGINFO_H


#include "../ConstantInfo.h"
#include <string>

class ConstantStringInfo : public ConstantInfo {
public:
    unsigned short index = 0;
    ConstantPool *constantPool;

    explicit ConstantStringInfo(ConstantPool *constantPool);

    void readInfo(ClassReader *reader) override;

    std::string getValue();
};


#endif //HOTPOTJVM_CONSTANTSTRINGINFO_H
