//
// Created by 屠昊天 on 2022/3/11.
//

#include "CodeAttribute.h"

namespace classFile {
    void CodeAttribute::readInfo(ClassReader *reader) {
        this->maxStack = reader->readUint16();
        this->maxLocals = reader->readUint16();
        auto codeLength = reader->readUint32();
        this->code = std::string(reader->readBytes(codeLength), codeLength);
        this->exceptionTable = readExceptionTable(reader);
        this->attributes = readAttributes(reader, constantPool);
    }

    std::vector<ExceptionTableEntry> CodeAttribute::readExceptionTable(ClassReader *reader) {
        auto length = reader->readUint16();
        auto table = std::vector<ExceptionTableEntry>(length);
        for (int i = 0; i < length; i++) {
            auto entry = ExceptionTableEntry{};
            entry.startPC = reader->readUint16();
            entry.endPC = reader->readUint16();
            entry.handlerPC = reader->readUint16();
            entry.catchType = reader->readUint16();
            table.push_back(entry);
        }
        return table;
    }

    CodeAttribute::CodeAttribute(ConstantPool *constantPool) : AttributeInfo(CODE) {
        this->constantPool = constantPool;
    }

}
