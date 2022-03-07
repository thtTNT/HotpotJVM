//
// Created by 屠昊天 on 2022/3/8.
//

#include<exception>
#include<string>

class CommandParseError : std::exception{
public:
    std::string message = "Command Parse Error";
};