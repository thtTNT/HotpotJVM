//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_ZIPENTRY_H
#define HOTPOTJVM_ZIPENTRY_H


#include "entry.h"
#include <string>

class ZipEntry : public Entry {
public:
    std::string absPath;

    explicit ZipEntry(std::string absPath);

    char *readClass(const std::string &className) override;

    std::string string() override;
};


#endif //HOTPOTJVM_ZIPENTRY_H
