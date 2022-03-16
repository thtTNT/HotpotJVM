//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTMEMBERREFINFO_H
#define HOTPOTJVM_CONSTANTMEMBERREFINFO_H


#include "../ConstantInfo.h"

namespace classFile {
    class ConstantMemberRefInfo : public ConstantInfo {
    private:
        ConstantPool *constantPool;
        unsigned short classIndex = 0;
        unsigned short nameAndTypeIndex = 0;
    public:
        explicit ConstantMemberRefInfo(unsigned short type, ConstantPool *constantPool);

        void readInfo(ClassReader *reader) override;

        std::string getClassName();

        std::string getName();

        std::string getDescription();
    };

    class ConstantFieldRefInfo : public ConstantMemberRefInfo {
    public:
        explicit ConstantFieldRefInfo(ConstantPool *constantPool) : ConstantMemberRefInfo(CONSTANT_FIELD_REF,
                                                                                          constantPool) {};
    };

    class ConstantMethodRefInfo : public ConstantMemberRefInfo {
    public:
        explicit ConstantMethodRefInfo(ConstantPool *constantPool) : ConstantMemberRefInfo(CONSTANT_METHOD_REF,
                                                                                           constantPool) {};
    };

    class ConstantInterfaceMethodRefInfo : public ConstantMemberRefInfo {
    public:
        explicit ConstantInterfaceMethodRefInfo(ConstantPool *constantPool) : ConstantMemberRefInfo(
                CONSTANT_INTERFACE_METHOD_REF,
                constantPool) {};
    };
}

#endif //HOTPOTJVM_CONSTANTMEMBERREFINFO_H
