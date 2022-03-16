//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_CONSTANTVALUEATTRIBUTE_H
#define HOTPOTJVM_CONSTANTVALUEATTRIBUTE_H


#include "../AttributeInfo.h"

namespace classFile {
    class ConstantValueAttribute : public AttributeInfo {
    public:
        unsigned short constantValueIndex = 0;

        ConstantValueAttribute();

        void readInfo(ClassReader *reader) override;
    };
}


#endif //HOTPOTJVM_CONSTANTVALUEATTRIBUTE_H
