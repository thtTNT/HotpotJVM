//
// Created by 屠昊天 on 2022/3/8.
//

#include "DirEntry.h"
#include "../exception/FileNotFoundException.h"

#include <utility>
#include <fstream>
#include <iostream>


DirEntry::DirEntry(std::string absDir) {
    this->absDir = std::move(absDir);
}

char *DirEntry::readClass(const std::string &className) {
    std::ifstream fin(this->absDir + className);
    if (fin.is_open()) {
        char *bs = nullptr;
        fin >> bs;
        fin.close();
        return bs;
    } else {
        throw FileNotFoundException{};
    }
}

std::string DirEntry::string() {
    std::cout << this->absDir << std::endl;
}
