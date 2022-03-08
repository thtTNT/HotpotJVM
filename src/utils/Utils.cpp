//
// Created by 屠昊天 on 2022/3/8.
//

#include "Utils.h"

std::vector<std::string> tools::string::split(const std::string &str, const std::string &pattern) {
    std::vector<std::string> result;
    if (str.empty()) {
        return result;
    }
    std::string tempStr = str;

    auto pos = tempStr.find(pattern);
    auto size = tempStr.size();

    while (pos != std::string::npos) {
        result.push_back(tempStr.substr(0, pos));
        tempStr = tempStr.substr(pos + pattern.size(), size);
        pos = tempStr.find(pattern);
    }
    return result;
}

bool tools::string::endWith(const std::string &str, const std::string &end) {
    if (str.length() >= end.length()) {
        return (0 == str.compare(str.length() - end.length(), end.length(), end));
    } else {
        return false;
    }
}
