//
// Created by 屠昊天 on 2022/3/8.
//

#include <iostream>
#include "CompositeEntry.h"
#include "../utils/Utils.h"

CompositeEntry::CompositeEntry(const std::string &pathListString) {
    auto pathList = tools::string::split(pathListString, ":");
    for (const auto &path : pathList) {
        this->entries.emplace_back(createEntry(path));
    }
}


std::string *CompositeEntry::readClass(const std::string &className) {
    for (auto entry : this->entries) {
        auto bs = entry->readClass(className);
        if (bs != nullptr) {
            return bs;
        }
    }
    return nullptr;
}

void CompositeEntry::string() {
    for (auto entry : this->entries) {
        entry->string();
    }
}
