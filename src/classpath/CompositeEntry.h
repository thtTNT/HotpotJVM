//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_COMPOSITEENTRY_H
#define HOTPOTJVM_COMPOSITEENTRY_H

#include <vector>
#include <string>

#include "entry.h"

class CompositeEntry : public Entry {
public:
    explicit CompositeEntry(const std::string &pathList);

    std::string *readClass(const std::string &className) override;

    void string() override;

private:
    std::vector<Entry *> entries;
};


#endif //HOTPOTJVM_COMPOSITEENTRY_H
