//
// Created by 屠昊天 on 2022/3/8.
//

#include "CommandParseError.h"

#include <utility>

CommandParseError::CommandParseError(std::string message) {
    this->message = std::move(message);
}
