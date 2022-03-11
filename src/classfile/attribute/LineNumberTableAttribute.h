//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_LINENUMBERTABLEATTRIBUTE_H
#define HOTPOTJVM_LINENUMBERTABLEATTRIBUTE_H

#include <vector>
#include "../AttributeInfo.h"

struct LineNumberTableEntry {
    unsigned short startPC;
    unsigned short lineNumber;
};

class LineNumberTableAttribute : public AttributeInfo {
public:
    std::vector<LineNumberTableEntry> lineNumberTable;
    void readInfo(ClassReader *reader) override;
};


#endif //HOTPOTJVM_LINENUMBERTABLEATTRIBUTE_H
