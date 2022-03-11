//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H
#define HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H


#include "../ConstantInfo.h"

class ConstantNameAndTypeInfo : public ConstantInfo {
private:
    unsigned short nameIndex = 0;
    unsigned short descriptorIndex = 0;
public:
    ConstantNameAndTypeInfo() : ConstantInfo(CONSTANT_NAME_AND_TYPE) {};

    void readInfo(ClassReader *reader) override;
};


#endif //HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H
