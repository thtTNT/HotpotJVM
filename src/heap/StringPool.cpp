//
// Created by 屠昊天 on 2022/3/19.
//

#include "StringPool.h"
#include "ClassLoader.h"
#include "Class.h"

std::map<std::string, heap::Object *> internedStrings;

heap::Object *heap::JString(heap::ClassLoader *loader, std::string str) {
    if (internedStrings[str] != nullptr) {
        return internedStrings[str];
    }

    auto jChars = new Object(loader->loadClass("[C"), DATA_TYPE_CHAR, str.size());
    for (int i = 0; i < str.size(); i++) {
        (*jChars->getShorts())[i] = str[i];
    }
    auto jStr = loader->loadClass("java/lang/String")->newObject();
    jStr->setRefVar("value", "[C", jChars);
    internedStrings[str] = jStr;
    return jStr;
}
