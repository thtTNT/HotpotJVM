//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_SYNTHETICATTRIBUTE_H
#define HOTPOTJVM_SYNTHETICATTRIBUTE_H


#include "../AttributeInfo.h"

class SyntheticAttribute : public AttributeInfo {
    void readInfo(ClassReader *reader) override;
};


#endif //HOTPOTJVM_SYNTHETICATTRIBUTE_H
