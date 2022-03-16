//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTDOUBLEINFO_H
#define HOTPOTJVM_CONSTANTDOUBLEINFO_H


#include "../ConstantInfo.h"

namespace classFile {
    class ConstantDoubleInfo : public ConstantInfo {
    public:
        double value = 0.0;

        explicit ConstantDoubleInfo() : ConstantInfo(CONSTANT_DOUBLE) {};

        void readInfo(ClassReader *reader) override;
    };

}

#endif //HOTPOTJVM_CONSTANTDOUBLEINFO_H
