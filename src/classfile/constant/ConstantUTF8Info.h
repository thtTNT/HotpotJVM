//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTUTF8INFO_H
#define HOTPOTJVM_CONSTANTUTF8INFO_H

#include <string>
#include "../ConstantInfo.h"

namespace classFile {

    class ConstantUTF8Info : public ConstantInfo {
    public:
        std::string value;

        ConstantUTF8Info() : ConstantInfo(CONSTANT_UTF8) {};

        void readInfo(ClassReader *reader) override;
    };

}

#endif //HOTPOTJVM_CONSTANTUTF8INFO_H
