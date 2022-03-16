//
// Created by 屠昊天 on 2022/3/9.
//

#ifndef HOTPOTJVM_CONSTANTCLASSINFO_H
#define HOTPOTJVM_CONSTANTCLASSINFO_H


#include "../ConstantInfo.h"
#include <string>

namespace classFile {

    class ConstantClassInfo : public ConstantInfo {
    private:
        ConstantPool *constantPool;
    public:
        unsigned short nameIndex = 0;

        explicit ConstantClassInfo(ConstantPool *constantPool);

        void readInfo(ClassReader *reader) override;

        std::string getName() const;
    };

}
#endif //HOTPOTJVM_CONSTANTCLASSINFO_H
