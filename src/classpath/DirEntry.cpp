//
// Created by 屠昊天 on 2022/3/8.
//

#include "DirEntry.h"
#include "../exception/FileNotFoundException.h"

#include <utility>
#include <fstream>
#include <iostream>
#include <vector>


DirEntry::DirEntry(std::string absDir) {
    this->absDir = std::move(absDir);
}

std::string *DirEntry::readClass(const std::string &className) {
    auto bs = new std::vector<char>();
    std::ifstream fin(this->absDir + className, std::ios::binary);
    if (fin.is_open()) {
        char chr;
        while (fin.get(chr)) {
            bs->push_back(chr);
        }
        fin.close();
        return new std::string(bs->data(), bs->size());
    } else {
        throw FileNotFoundException{};
    }
}

void DirEntry::string() {
    std::cout << this->absDir << std::endl;
}
