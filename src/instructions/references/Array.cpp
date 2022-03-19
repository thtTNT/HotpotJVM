//
// Created by 屠昊天 on 2022/3/19.
//

#include "Array.h"
#include "../../exception/RuntimeException.h"
#include "../../exception/NullPointerException.h"

void NEW_ARRAY::fetchOperands(ByteCodeReader *reader) {
    this->aType = reader->readUint8();
}

void NEW_ARRAY::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto count = stack->popInt();
    if (count < 0) {
        throw RuntimeException("java.lang.NegativeArraySizeException");
    }
    auto classLoader = frame->getMethod()->clazz->loader;
    auto arrayClass = getPrimitiveArrayClass(classLoader, aType);
    auto array = arrayClass->newArray((unsigned) count);
    stack->pushRef(array);
}

heap::Class *getPrimitiveArrayClass(heap::ClassLoader *loader, unsigned char aType) {
    switch (aType) {
        case AT_BOOLEAN:
            return loader->loadClass("[Z");
        case AT_BYTE:
            return loader->loadClass("[B");
        case AT_CHAR:
            return loader->loadClass("[C");
        case AT_SHORT:
            return loader->loadClass("[S");
        case AT_INT:
            return loader->loadClass("[I");
        case AT_LONG:
            return loader->loadClass("[J");
        case AT_FLOAT:
            return loader->loadClass("[F");
        case AT_DOUBLE:
            return loader->loadClass("[D");
        default:
            throw RuntimeException("Invalid array type");
    }
}

void ANEW_ARRAY::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto classRef = static_cast<heap::ClassRef *>(constantPool->getConstant(this->index).symRef);
    auto componentClass = classRef->resolvedClass();
    auto stack = frame->operandStack;
    auto count = stack->popInt();
    if (count < 0) {
        throw RuntimeException("java.lang.NegativeArraySizeException");
    }
    auto arrayClass = componentClass->getArrayClass();
    auto array = arrayClass->newArray((unsigned) count);
    stack->pushRef(array);
}

void ARRAY_LENGTH::execute(Frame *frame) {
    auto stack = frame->operandStack;
    auto arrayRef = stack->popRef();
    if (arrayRef == nullptr) {
        throw NullPointerException();
    }

    auto len = arrayRef->arrayLength();
    stack->pushInt(len);
}

void MULTI_ANEW_ARRAY::fetchOperands(ByteCodeReader *reader) {
    this->index = reader->readUint16();
    this->dimensions = reader->readUint8();
}

std::vector<int> popAndCheckCounts(OperandStack *stack, int dimensions) {
    auto counts = std::vector<int>(dimensions);
    for (int i = dimensions - 1; i >= 0; i--) {
        counts[i] = stack->popInt();
        if (counts[i] < 0) {
            throw RuntimeException("java.lang.NegativeArraySizeException");
        }
    }
    return counts;
}

heap::Object *newMultiDimensionalArray(std::vector<int> counts, heap::Class *arrayClass, int dimensionIndex) {
    auto count = counts[dimensionIndex];
    auto array = arrayClass->newArray(count);
    if (dimensionIndex < counts.size()) {
        auto refs = array->getRefs();
        for (int index = 0; index < count; index++) {
            (*refs)[index] = newMultiDimensionalArray(counts, arrayClass, dimensionIndex + 1);
        }
    }
    return array;
}

void MULTI_ANEW_ARRAY::execute(Frame *frame) {
    auto constantPool = frame->getMethod()->getClass()->constantPool;
    auto classRef = static_cast<heap::ClassRef *>(constantPool->getConstant(this->index).symRef);
    auto arrayClass = classRef->resolvedClass();
    auto stack = frame->operandStack;
    auto counts = popAndCheckCounts(stack, dimensions);
    auto array = newMultiDimensionalArray(counts, arrayClass, 0);
    stack->pushRef(array);
}
