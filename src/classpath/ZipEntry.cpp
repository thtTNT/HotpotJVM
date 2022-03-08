//
// Created by 屠昊天 on 2022/3/8.
//

#include "ZipEntry.h"
#include "zip.h"
#include "../exception/FileNotFoundException.h"

#include <utility>
#include <iostream>

ZipEntry::ZipEntry(std::string absPath) {
    this->absPath = std::move(absPath);
}

char *ZipEntry::readClass(const std::string &className) {
    // Unzip the file
    int error = 0;
    zip *z = zip_open(this->absPath.c_str(), ZIP_RDONLY, &error);
    if (z == nullptr) {
        return nullptr;
    }

    // Search for class
    struct zip_stat st{};
    zip_stat_init(&st);
    error = zip_stat(z, className.c_str(), ZIP_FL_ENC_GUESS, &st);
    if (st.valid == 0){
        return nullptr;
    }

    char *content = new char[st.size];
    zip_file *file = zip_fopen(z, className.c_str(), ZIP_FL_ENC_GUESS);
    zip_fread(file, content, st.size);
    zip_fclose(file);

    zip_close(z);
    return content;
}

std::string ZipEntry::string() {
    return this->absPath;
}
