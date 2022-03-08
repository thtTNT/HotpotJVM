//
// Created by 屠昊天 on 2022/3/8.
//

#ifndef HOTPOTJVM_FILENOTFOUNDEXCEPTION_H
#define HOTPOTJVM_FILENOTFOUNDEXCEPTION_H
#include <string>


class FileNotFoundException : std::exception {
public:
    const std::string message = "File not found";
};


#endif //HOTPOTJVM_FILENOTFOUNDEXCEPTION_H
