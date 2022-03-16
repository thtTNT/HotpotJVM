//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_CODEATTRIBUTE_H
#define HOTPOTJVM_CODEATTRIBUTE_H


#include "../AttributeInfo.h"

namespace classFile {
    struct ExceptionTableEntry {
        unsigned short startPC;
        unsigned short endPC;
        unsigned short handlerPC;
        unsigned short catchType;
    };

    class CodeAttribute : public AttributeInfo {
    private:
        ConstantPool *constantPool;

        static std::vector<ExceptionTableEntry> readExceptionTable(ClassReader *reader);

    public:
        unsigned short maxStack = 0;
        unsigned short maxLocals = 0;
        std::string code;
        std::vector<ExceptionTableEntry> exceptionTable;
        std::vector<AttributeInfo *> attributes;

        explicit CodeAttribute(ConstantPool *constantPool);

        void readInfo(ClassReader *reader) override;

    };
}


#endif //HOTPOTJVM_CODEATTRIBUTE_H
