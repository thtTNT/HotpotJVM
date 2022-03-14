//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_EXCEPTIONSATTRIBUTE_H
#define HOTPOTJVM_EXCEPTIONSATTRIBUTE_H


#include "../AttributeInfo.h"

class ExceptionsAttribute : public AttributeInfo {
private:
    std::vector<unsigned short> indexTable;
public:
    ExceptionsAttribute();

    void readInfo(ClassReader *reader) override;

    std::vector<unsigned short> getIndexTable();
};


#endif //HOTPOTJVM_EXCEPTIONSATTRIBUTE_H
