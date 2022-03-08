//
// Created by 屠昊天 on 2022/3/8.
//

#include "entry.h"
#include "CompositeEntry.h"
#include "../utils/Utils.h"
#include "ZipEntry.h"
#include "DirEntry.h"
#include "boost/filesystem.hpp"

using namespace boost::filesystem;

Entry *createEntry(const std::string &path) {
    // CompositeEntry
    if (path.find(':') != std::string::npos) {
        return new CompositeEntry(path);
    }
    // WildcardEntry
    if (tools::string::endWith(path, "*")) {
        auto baseDir = path.substr(0, path.length() - 1);
        std::string pathListString;
        directory_iterator it(baseDir);
        directory_iterator directory_end;
        for (; it != directory_end; it++) {
            if (is_directory(*it)){
                continue;
            }
            auto filename = it->path().filename().string();
            if (tools::string::endWith(filename, ".jar") || tools::string::endWith(filename, ".JAR") ||
                tools::string::endWith(filename, ".zip") || tools::string::endWith(filename, ".ZIP")) {
                pathListString += baseDir + filename + ":";
            }
        }
        pathListString.substr(0, pathListString.length() - 1);
        return new CompositeEntry(pathListString);
    }
    // ZipEntry
    if (tools::string::endWith(path, ".jar") || tools::string::endWith(path, ".JAR") ||
        tools::string::endWith(path, ".zip") || tools::string::endWith(path, ".ZIP")) {
        return new ZipEntry(path);
    }
    return new DirEntry(path);
}

char *Entry::readClass(const std::string &className) {
    return nullptr;
}

