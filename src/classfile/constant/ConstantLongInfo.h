//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTLONGINFO_H
#define HOTPOTJVM_CONSTANTLONGINFO_H


#include "../ConstantInfo.h"

namespace classFile {
    class ConstantLongInfo : public ConstantInfo {
    public:
        long value = 0;

        explicit ConstantLongInfo() : ConstantInfo(CONSTANT_LONG) {};

        void readInfo(ClassReader *reader) override;
    };
}


#endif //HOTPOTJVM_CONSTANTLONGINFO_H
