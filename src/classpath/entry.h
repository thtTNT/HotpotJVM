//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_ENTRY_H
#define HOTPOTJVM_ENTRY_H

#include <string>


class Entry {
public:
    virtual std::string *readClass(const std::string &className) = 0;

    virtual void string() = 0;
};

Entry *createEntry(const std::string &path);

#endif //HOTPOTJVM_ENTRY_H
