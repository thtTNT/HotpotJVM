//
// Created by 屠昊天 on 2022/3/13.
//

#include "Wide.h"
#include "../load/ILoad.h"
#include "../load/LLoad.h"
#include "../load/FLoad.h"
#include "../load/DLoad.h"
#include "../load/ALoad.h"
#include "../store/IStore.h"
#include "../store/LStore.h"
#include "../store/FStore.h"
#include "../store/DStore.h"
#include "../store/AStore.h"
#include "../math/IINC.h"
#include "../../exception/ClassNotSupportException.h"

void WIDE::fetchOperands(ByteCodeReader *reader) {
    auto opcode = reader->readUint8();
    switch (opcode) {
        case INS_CODE_ILOAD: {
            auto ins = new ILOAD();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_LLOAD: {
            auto ins = new LLOAD();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_FLOAD: {
            auto ins = new FLOAD();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_DLOAD: {
            auto ins = new DLOAD();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_ALOAD: {
            auto ins = new ALOAD();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_ISTORE: {
            auto ins = new ISTORE();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_LSTORE: {
            auto ins = new LSTORE();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_FSTORE: {
            auto ins = new FSTORE();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_DSTORE: {
            auto ins = new DSTORE();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_ASTORE: {
            auto ins = new ASTORE();
            ins->index = reader->readUint16();
            this->modifiedInstruction = ins;
            break;
        }
        case INS_CODE_IINC: {
            auto ins = new IINC();
            ins->index = reader->readUint16();
            ins->value = reader->readInt32();
            this->modifiedInstruction = ins;
            break;
        }
        default: {
            throw ClassNotSupportException();
        }
    }
}

void WIDE::execute(Frame *frame) {
    this->modifiedInstruction->execute(frame);
}
