//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_DIRENTRY_H
#define HOTPOTJVM_DIRENTRY_H

#include <string>
#include "entry.h"

class DirEntry : public Entry{
public:
    std::string absDir;
    explicit DirEntry(std::string absDir);
    char * readClass(const std::string &className) override;
    std::string string() override;
};


#endif //HOTPOTJVM_DIRENTRY_H
