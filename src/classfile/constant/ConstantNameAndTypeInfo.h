//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H
#define HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H


#include "../ConstantInfo.h"

namespace classFile {
    class ConstantNameAndTypeInfo : public ConstantInfo {
    private:
        ConstantPool *constantPool;
        unsigned short nameIndex = 0;
        unsigned short descriptorIndex = 0;
    public:
        ConstantNameAndTypeInfo(ConstantPool *constantPool);

        void readInfo(ClassReader *reader) override;

        std::string getName();

        std::string getDescription();
    };
}

#endif //HOTPOTJVM_CONSTANTNAMEANDTYPEINFO_H
