//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTINTEGERINFO_H
#define HOTPOTJVM_CONSTANTINTEGERINFO_H


#include "../ConstantInfo.h"

class ConstantIntegerInfo : public ConstantInfo {
public:
    int value = 0;

    explicit ConstantIntegerInfo() : ConstantInfo(CONSTANT_INTEGER) {};

    void readInfo(ClassReader *reader) override;
};


#endif //HOTPOTJVM_CONSTANTINTEGERINFO_H
