//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_UTILS_H
#define HOTPOTJVM_UTILS_H

#include <vector>
#include <string>

namespace tools {
    namespace string {
        std::vector<std::string> split(const std::string &str, const std::string &pattern);
        bool endWith(const std::string &str, const std::string &end);
    }
}


#endif //HOTPOTJVM_UTILS_H
