//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_UNPARSEDATTRIBUTE_H
#define HOTPOTJVM_UNPARSEDATTRIBUTE_H


#include "../AttributeInfo.h"

class UnparsedAttribute : public AttributeInfo {
public:
    std::string name;
    unsigned int length;
    std::string info;

    UnparsedAttribute(std::string name, unsigned int length);

    void readInfo(ClassReader *reader) override;
};


#endif //HOTPOTJVM_UNPARSEDATTRIBUTE_H
