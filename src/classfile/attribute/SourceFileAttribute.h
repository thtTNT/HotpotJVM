//
// Created by 屠昊天 on 2022/3/11.
//

#ifndef HOTPOTJVM_SOURCEFILEATTRIBUTE_H
#define HOTPOTJVM_SOURCEFILEATTRIBUTE_H


#include "../AttributeInfo.h"

namespace classFile {
    class SourceFileAttribute : public AttributeInfo {
    private:
        ConstantPool *constantPool;
    public:
        unsigned short sourceFileIndex;

        explicit SourceFileAttribute(ConstantPool *constantPool);

        void readInfo(ClassReader *reader) override;

        std::string filename();
    };
}


#endif //HOTPOTJVM_SOURCEFILEATTRIBUTE_H
