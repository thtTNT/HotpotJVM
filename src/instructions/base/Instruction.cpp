//
// Created by 屠昊天 on 2022/3/12.
//

#include "Instruction.h"
#include "../constant/Const.h"
#include "../constant/IPush.h"
#include "../../exception/InstructionNotSupport.h"
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
#include "../stack/Pop.h"
#include "../stack/Dup.h"
#include "../stack/Swap.h"
#include "../math/Add.h"
#include "../math/Sub.h"
#include "../math/Mul.h"
#include "../math/Div.h"
#include "../math/Rem.h"
#include "../math/Neg.h"
#include "../math/Sh.h"
#include "../math/And.h"
#include "../math/Or.h"
#include "../math/Xor.h"
#include "../math/IINC.h"
#include "../conversions/I2x.h"
#include "../conversions/L2x.h"
#include "../conversions/F2x.h"
#include "../conversions/D2x.h"
#include "../comparisons/LCmp.h"
#include "../comparisons/FCmp.h"
#include "../comparisons/DCmp.h"
#include "../comparisons/IfCond.h"
#include "../comparisons/IfICmp.h"
#include "../comparisons/IfACmp.h"
#include "../control/Goto.h"
#include "../control/TableSwitch.h"
#include "../control/LookupSwitch.h"
#include "../extended/Wide.h"
#include "../extended/IfNull.h"
#include "../extended/GotoW.h"

void NoOperandsInstruction::fetchOperands(ByteCodeReader *reader) {

}

void NoOperandsInstruction::execute(Frame *frame) {

}

void BranchInstruction::fetchOperands(ByteCodeReader *reader) {
    this->offset = reader->readInt16();
}

void Index8Instruction::fetchOperands(ByteCodeReader *reader) {
    this->index = reader->readUint8();
}

void Index16Instruction::fetchOperands(ByteCodeReader *reader) {
    this->index = reader->readUint16();
}

Instruction *newInstruction(unsigned char opcode) {
    switch (opcode) {
        case INS_CODE_NOPE:
            return new NOPE();
        case INS_CODE_ACONST_NULL:
            return new ACONST_NULL();
        case INS_CODE_ICONST_0:
            return new ICONST_0();
        case INS_CODE_ICONST_1:
            return new ICONST_1();
        case INS_CODE_ICONST_2:
            return new ICONST_2();
        case INS_CODE_ICONST_3:
            return new ICONST_3();
        case INS_CODE_ICONST_4:
            return new ICONST_4();
        case INS_CODE_ICONST_5:
            return new ICONST_5();
        case INS_CODE_LCONST_0:
            return new LCONST_0();
        case INS_CODE_LCONST_1:
            return new LCONST_1();
        case INS_CODE_FCONST_0:
            return new FCONST_0();
        case INS_CODE_FCONST_1:
            return new FCONST_1();
        case INS_CODE_FCONST_2:
            return new FCONST_2();
        case INS_CODE_DCONST_0:
            return new DCONST_0();
        case INS_CODE_DCONST_1:
            return new DCONST_1();
        case INS_CODE_BIPUSH:
            return new BIPUSH();
        case INS_CODE_SIPUSH:
            return new SIPUSH();
        case INS_CODE_ILOAD:
            return new ILOAD();
        case INS_CODE_LLOAD:
            return new LLOAD();
        case INS_CODE_FLOAD:
            return new FLOAD();
        case INS_CODE_DLOAD:
            return new DLOAD();
        case INS_CODE_ALOAD:
            return new ALOAD();
        case INS_CODE_ILOAD_0:
            return new ILOAD_0();
        case INS_CODE_ILOAD_1:
            return new ILOAD_1();
        case INS_CODE_ILOAD_2:
            return new ILOAD_2();
        case INS_CODE_ILOAD_3:
            return new ILOAD_3();
        case INS_CODE_LLOAD_0:
            return new LLOAD_0();
        case INS_CODE_LLOAD_1:
            return new LLOAD_1();
        case INS_CODE_LLOAD_2:
            return new LLOAD_2();
        case INS_CODE_LLOAD_3:
            return new LLOAD_3();
        case INS_CODE_FLOAD_0:
            return new FLOAD_0();
        case INS_CODE_FLOAD_1:
            return new FLOAD_1();
        case INS_CODE_FLOAD_2:
            return new FLOAD_2();
        case INS_CODE_FLOAD_3:
            return new FLOAD_3();
        case INS_CODE_DLOAD_0:
            return new DLOAD_0();
        case INS_CODE_DLOAD_1:
            return new DLOAD_1();
        case INS_CODE_DLOAD_2:
            return new DLOAD_2();
        case INS_CODE_DLOAD_3:
            return new DLOAD_3();
        case INS_CODE_ALOAD_0:
            return new ALOAD_0();
        case INS_CODE_ALOAD_1:
            return new ALOAD_1();
        case INS_CODE_ALOAD_2:
            return new ALOAD_2();
        case INS_CODE_ALOAD_3:
            return new ALOAD_3();
        case INS_CODE_ISTORE:
            return new ISTORE();
        case INS_CODE_LSTORE:
            return new LSTORE();
        case INS_CODE_FSTORE:
            return new FSTORE();
        case INS_CODE_DSTORE:
            return new DSTORE();
        case INS_CODE_ASTORE:
            return new ASTORE();
        case INS_CODE_ISTORE_0:
            return new ISTORE_0();
        case INS_CODE_ISTORE_1:
            return new ISTORE_1();
        case INS_CODE_ISTORE_2:
            return new ISTORE_2();
        case INS_CODE_ISTORE_3:
            return new ISTORE_3();
        case INS_CODE_LSTORE_0:
            return new LSTORE_0();
        case INS_CODE_LSTORE_1:
            return new LSTORE_1();
        case INS_CODE_LSTORE_2:
            return new LSTORE_2();
        case INS_CODE_LSTORE_3:
            return new LSTORE_3();
        case INS_CODE_FSTORE_0:
            return new FSTORE_0();
        case INS_CODE_FSTORE_1:
            return new FSTORE_1();
        case INS_CODE_FSTORE_2:
            return new FSTORE_2();
        case INS_CODE_FSTORE_3:
            return new FSTORE_3();
        case INS_CODE_DSTORE_0:
            return new DSTORE_0();
        case INS_CODE_DSTORE_1:
            return new DSTORE_1();
        case INS_CODE_DSTORE_2:
            return new DSTORE_2();
        case INS_CODE_DSTORE_3:
            return new DSTORE_3();
        case INS_CODE_ASTORE_0:
            return new ASTORE_0();
        case INS_CODE_ASTORE_1:
            return new ASTORE_1;
        case INS_CODE_ASTORE_2:
            return new ASTORE_2();
        case INS_CODE_ASTORE_3:
            return new ASTORE_3();
        case INS_CODE_POP:
            return new POP();
        case INS_CODE_POP2:
            return new POP2();
        case INS_CODE_DUP:
            return new DUP();
        case INS_CODE_DUP_X2:
            return new DUP_X2();
        case INS_CODE_DUP2:
            return new DUP2();
        case INS_CODE_DUP2_X1:
            return new DUP2_X1();
        case INS_CODE_DUP2_X2:
            return new DUP2_X2();
        case INS_CODE_SWAP:
            return new SWAP();
        case INS_CODE_IADD:
            return new IADD();
        case INS_CODE_LADD:
            return new LADD();
        case INS_CODE_FADD:
            return new FADD();
        case INS_CODE_DADD:
            return new DADD();
        case INS_CODE_ISUB:
            return new ISUB();
        case INS_CODE_LSUB:
            return new LSUB();
        case INS_CODE_FSUB:
            return new FSUB();
        case INS_CODE_DSUB:
            return new DSUB();
        case INS_CODE_IMUL:
            return new IMUL();
        case INS_CODE_LMUL:
            return new LMUL();
        case INS_CODE_FMUL:
            return new FMUL();
        case INS_CODE_DMUL:
            return new DMUL();
        case INS_CODE_IDIV:
            return new IDIV();
        case INS_CODE_LDIV:
            return new LDIV();
        case INS_CODE_FDIV:
            return new FDIV();
        case INS_CODE_DDIV:
            return new DDIV();
        case INS_CODE_IREM:
            return new IREM();
        case INS_CODE_LREM:
            return new LREM();
        case INS_CODE_FREM:
            return new FREM();
        case INS_CODE_DREM:
            return new DREM();
        case INS_CODE_INEG:
            return new INEG();
        case INS_CODE_LNEG:
            return new LNEG();
        case INS_CODE_FNEG:
            return new FNEG();
        case INS_CODE_DNEG:
            return new DNEG();
        case INS_CODE_ISHL:
            return new ISHL();
        case INS_CODE_LSHL:
            return new LSHL();
        case INS_CODE_ISHR:
            return new ISHR();
        case INS_CODE_LSHR:
            return new LSHR();
        case INS_CODE_IUSHR:
            return new IUSHR();
        case INS_CODE_LUSHR:
            return new LUSHR();
        case INS_CODE_IAND:
            return new IAND();
        case INS_CODE_LAND:
            return new LAND();
        case INS_CODE_IOR:
            return new IOR();
        case INS_CODE_LOR:
            return new LOR();
        case INS_CODE_IXOR:
            return new IXOR();
        case INS_CODE_LXOR:
            return new LXOR();
        case INS_CODE_IINC:
            return new IINC();
        case INS_CODE_I2L:
            return new I2L();
        case INS_CODE_I2F:
            return new I2F();
        case INS_CODE_I2D:
            return new I2D();
        case INS_CODE_L2I:
            return new L2I();
        case INS_CODE_L2F:
            return new L2F();
        case INS_CODE_L2D:
            return new L2D();
        case INS_CODE_F2I:
            return new F2I();
        case INS_CODE_F2L:
            return new F2L();
        case INS_CODE_F2D:
            return new F2D();
        case INS_CODE_D2I:
            return new D2I();
        case INS_CODE_D2L:
            return new D2L();
        case INS_CODE_D2F:
            return new D2F();
        case INS_CODE_LCMP:
            return new LCMP();
        case INS_CODE_FCMPL:
            return new FCMPL();
        case INS_CODE_FCMPG:
            return new FCMPG();
        case INS_CODE_DCMPL:
            return new DCMPL();
        case INS_CODE_DCMPG:
            return new DCMPG();
        case INS_CODE_IFEQ:
            return new IFEQ();
        case INS_CODE_IFNE:
            return new IFNE();
        case INS_CODE_IFLT:
            return new IFLT();
        case INS_CODE_IFGE:
            return new IFGE();
        case INS_CODE_IFGT:
            return new IFGT();
        case INS_CODE_IFLE:
            return new IFLE();
        case INS_CODE_IF_ICMPEQ:
            return new IF_ICMPEQ();
        case INS_CODE_IF_ICMPNE:
            return new IF_ICMPNE();
        case INS_CODE_IF_ICMPLT:
            return new IF_ICMPLT();
        case INS_CODE_IF_ICMPGE:
            return new IF_ICMPGE();
        case INS_CODE_IF_ICMPGT:
            return new IF_ICMPGT();
        case INS_CODE_IF_ICMPLE:
            return new IF_ICMPLE();
        case INS_CODE_IF_ACMPEQ:
            return new IF_ACMPEQ();
        case INS_CODE_IF_ACMPNE:
            return new IF_ACMPNE();
        case INS_CODE_GOTO:
            return new GOTO();
        case INS_CODE_TABLE_SWITCH:
            return new TABLE_SWITCH();
        case INS_CODE_LOOKUP_SWITCH:
            return new LOOKUP_SWITCH();
        case INS_CODE_WIDE:
            return new WIDE();
        case INS_CODE_IFNULL:
            return new IFNULL();
        case INS_CODE_IFNONNULL:
            return new IFNONNULL();
        case INS_CODE_GOTO_W:
            return new GOTO_W();
        default:
            throw InstructionNotSupport(opcode);
    }
}
