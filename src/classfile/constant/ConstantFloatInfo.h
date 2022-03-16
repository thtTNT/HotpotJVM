//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTFLOATINFO_H
#define HOTPOTJVM_CONSTANTFLOATINFO_H


#include "../ConstantInfo.h"

namespace classFile {
    class ConstantFloatInfo : public ConstantInfo {
    public:
        float value = 0.0;

        explicit ConstantFloatInfo() : ConstantInfo(CONSTANT_FLOAT) {};

        void readInfo(ClassReader *reader) override;
    };
}

#endif //HOTPOTJVM_CONSTANTFLOATINFO_H
