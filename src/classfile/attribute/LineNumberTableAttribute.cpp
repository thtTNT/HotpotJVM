//
// Created by 屠昊天 on 2022/3/11.
//

#include "LineNumberTableAttribute.h"

void LineNumberTableAttribute::readInfo(ClassReader *reader) {
    auto length = reader->readUint16();
    this->lineNumberTable = std::vector<LineNumberTableEntry>(length);
    for (int i = 0; i < length; i++) {
        auto entry = LineNumberTableEntry();
        entry.startPC = reader->readUint16();
        entry.lineNumber = reader->readUint16();
        this->lineNumberTable[i] = entry;
    }
}
